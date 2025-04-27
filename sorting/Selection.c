#include <stdio.h>

void SelectionSort(int arr[],int n){
    int mini;
    for(int i = 0 ; i < n - 1; i +=1){
        mini = i;
        for(int j = i; j < n; j+=1){
            if(arr[j] < arr[mini]) mini = j;
        }
        int e = arr[i];
        arr[i] = arr[mini];
        arr[mini] = e;
    }
}

int main() {
    int arr[] = {2, 3, 1, 4, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    SelectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
