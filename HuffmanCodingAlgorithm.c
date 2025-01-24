#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256

// Node structure for Huffman Tree
struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char data, unsigned freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to build a simple Huffman Tree (for simplicity)
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node* root = createNode('$', 0);
    for (int i = 0; i < size; i++) {
        struct Node* newNode = createNode(data[i], freq[i]);
        // Add node as a leaf for simplicity (no actual sorting or min heap)
        if (!root->left) root->left = newNode;
        else root->right = newNode;
    }
    return root;
}

// Simple function to print Huffman codes (assumes left=0, right=1)
void printHuffmanCodes(struct Node* root, char code[], int top) {
    if (root->left) {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }
    if (!(root->left || root->right)) {
        code[top] = '\0';
        printf("%c: %s\n", root->data, code);
    }
}

// Function to calculate the frequency of characters in input
void calculateFrequency(char str[], char data[], int freq[], int* size) {
    int count[MAX_CHAR] = {0};
    for (int i = 0; str[i]; i++) count[(unsigned char)str[i]]++;

    *size = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (count[i]) {
            data[*size] = i;
            freq[*size] = count[i];
            (*size)++;
        }
    }
}

int main() {
    char str[1000], data[MAX_CHAR], code[MAX_CHAR];
    int freq[MAX_CHAR], size;

    printf("Enter text: ");
    fgets(str, 1000, stdin);

    calculateFrequency(str, data, freq, &size);

    struct Node* root = buildHuffmanTree(data, freq, size);

    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, 0);

    int original_size = strlen(str) * 8; // Original size in bits
    printf("Original size: %d bits\n", original_size);
    // Compressed size approximation
    printf("Compressed size: %d bits (approximation)\n", size * 8);

    return 0;
}
