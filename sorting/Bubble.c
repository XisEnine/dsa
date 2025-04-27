#include <stdio.h>

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
	for (int j = 0; j < n - i - 1; j++) {
	    if (arr[j] > arr[j + 1]) {
		// Swap elements
		int temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
	    }
	}
    }
}

int main() {
    int arr[] = {2, 3, 1, 4, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
