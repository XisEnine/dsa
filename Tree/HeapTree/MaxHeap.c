#include <stdio.h>
#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapifyUp(int index) {
  if (index <= 0)
    return;

  int parent = (index - 1) / 2;
  if (heap[parent] < heap[index]) {
    swap(&heap[parent], &heap[index]);
    heapifyUp(parent);
  }
}

void heapifyDown(int index) {
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < size && heap[left] > heap[largest])
    largest = left;
  if (right < size && heap[right] > heap[largest])
    largest = right;

  if (largest != index) {
    swap(&heap[index], &heap[largest]);
    heapifyDown(largest);
  }
}

void insert(int value) {
  if (size == MAX_SIZE) {
    printf("Heap is full\n");
    return;
  }

  heap[size] = value;
  heapifyUp(size);
  size++;
}

void deleteAtIndex(int index) {
  if (index >= size || index < 0) {
    printf("Invalid index\n");
    return;
  }

  heap[index] = heap[size - 1];
  size--;

  if (index > 0 && heap[(index - 1) / 2] < heap[index]) {
    heapifyUp(index);
  } else {
    heapifyDown(index);
  }
}

void printHeap() {
  for (int i = 0; i < size; i++)
    printf("%d ", heap[i]);
  printf("\n");
}

// Functions to perform Heap Sort separately
void heapifyForSort(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapifyForSort(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  // Build the max heap
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapifyForSort(arr, n, i);
  }

  // Extract elements from heap one by one
  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapifyForSort(arr, i, 0); // Only heapify the reduced heap (size = i)
  }
}

int main() {
  insert(50);
  insert(45);
  insert(35);
  insert(33);
  insert(16);
  insert(25);
  insert(34);
  insert(12);
  insert(10);

  printf("Max Heap: ");
  printHeap();

  deleteAtIndex(2); // Delete element at index 2
  printf("Heap after deletion at index 2: ");
  printHeap();

  // Make a copy for heap sort, because sorting destroys heap structure
  int arr[MAX_SIZE];
  int n = size;
  for (int i = 0; i < n; i++) {
    arr[i] = heap[i];
  }

  heapSort(arr, n);
  printf("Heap after HeapSort: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
