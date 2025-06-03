package ArraysAndHashing;

class lc_2149 {
    // For testing purposes
    public static void main(String[] args) {
        lc_2149 solution = new lc_2149();
        int[] nums = {3, 1, -2, -5, 2, -4};
        int[] result = solution.rearrangeArray(nums);

        for (int num : result) {
            System.out.print(num + " ");
        }
    }

    public int[] rearrangeArray(int[] nums) {
        int pos_index = 0;
        int neg_index = 1;
        int n = nums.length;
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                arr[pos_index] = nums[i];
                pos_index += 2;
            } else {
                arr[neg_index] = nums[i];
                neg_index += 2;
            }
        }

        return arr;
    }
}
