package ArraysAndHashing;

class lc_283 {
    public void moveZeroes(int[] arr) {
        int zpos = -1;
        int n = arr.length;

        // Find the first zero position
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zpos = i;
                break;
            }
        }

        // If no zero is found, array is already in the desired state
        if (zpos == -1) {
            return;
        }

        // Traverse from the next position and swap non-zero elements to the zero position
        for (int j = zpos + 1; j < n; j++) {
            if (arr[j] != 0) {
                arr[zpos] = arr[j];
                arr[j] = 0;
                zpos++;
            }
        }
    }

    // For testing purposes
    public static void main(String[] args) {
        lc_283 solution = new lc_283();
        int[] arr = {0, 1, 0, 3, 12};
        solution.moveZeroes(arr);

        // Print the result
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
