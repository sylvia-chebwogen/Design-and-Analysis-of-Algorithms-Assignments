#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
int* merge(int* arr1, int size1, int* arr2, int size2) {
    int* mergedArray = (int*)malloc((size1 + size2) * sizeof(int)); // dynamically allocate memory for merged array
    int i = 0, j = 0, k = 0;

    // Merge the two arrays
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }

    // Add remaining elements of arr1
    while (i < size1) {
        mergedArray[k++] = arr1[i++];
    }

    // Add remaining elements of arr2 
    while (j < size2) {
        mergedArray[k++] = arr2[j++];
    }

    return mergedArray;
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int* mergedArray = merge(arr1, size1, arr2, size2);
    int mergedSize = size1 + size2;

    printf("Merged array: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    free(mergedArray); 
    return 0;
}
