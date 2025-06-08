package Arrays;

public class lc_189 {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    static void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    static void printArray(int[] nums) {
        for (int num : nums) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        lc_189 solution = new lc_189();

        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        System.out.print("Original array: ");
        printArray(arr);

        solution.rotate(arr, 3);

        System.out.print("Rotated array: ");
        printArray(arr);
    }
}
