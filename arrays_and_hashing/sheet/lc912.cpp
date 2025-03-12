#include <vector>
using namespace std;

class Solution {
public:
    // Merge function to combine two sorted halves of the array
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1; // Size of the left half
        int n2 = right - mid;    // Size of the right half

        // Temporary arrays to store the two halves
        vector<int> leftArr(n1), rightArr(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; ++i)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; ++j)
            rightArr[j] = arr[mid + 1 + j];

        // Merge the two halves back into the original array
        int i = 0, j = 0, k = left; // Indices for leftArr, rightArr, and arr
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Copy any remaining elements from leftArr
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        // Copy any remaining elements from rightArr
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    // Merge Sort function
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2; // Calculate middle index

            // Recursively sort the two halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }

    // Entry point for sorting the array
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1); // Sort the entire array
        return nums;
    }
};