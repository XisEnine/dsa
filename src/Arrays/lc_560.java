package Arrays;

import java.util.HashMap;

public class lc_560 {

    // Main method for testing
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, 2, 3, -2, 5};
        int k = 5;
        int result = sol.subarraySum(nums, k);

        System.out.println("Total subarrays with sum " + k + " = " + result);
    }

    // Inner Solution class containing the subarraySum method
    static class Solution {
        public int subarraySum(int[] nums, int k) {
            HashMap<Integer, Integer> map = new HashMap<>();
            map.put(0, 1);
            int n = nums.length;
            int cnt = 0, sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                int rem = sum - k;
                if (map.containsKey(rem)) {
                    cnt += map.get(rem);
                }
                map.put(sum, map.getOrDefault(sum, 0) + 1);
            }
            return cnt;
        }
    }
}
