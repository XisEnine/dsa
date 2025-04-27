#include <stdio.h>

void insertSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
	int j = i;
	while (j > 0 && arr[j - 1] > arr[j]) {
	    int temp = arr[j - 1];
	    arr[j - 1] = arr[j];
	    arr[j] = temp;
	    j -= 1;
	}
    }
}

int main() {
    int arr[] = {2, 3, 1, 4, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
