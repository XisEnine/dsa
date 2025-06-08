package Arrays;

import java.util.HashMap;
import java.util.Scanner;

class Solution {
    // Function to find the length of the longest subarray with sum = k
    public int longestSubarray(int[] arr, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();

        int n = arr.length;
        int sum = 0, maxi = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == k) {
                maxi = i + 1;
            }

            int rem = sum - k;

            if (map.containsKey(rem)) {
                int len = i - map.get(rem);
                maxi = Math.max(len, maxi);
            }


            if (!map.containsKey(sum)) {
                map.put(sum, i);
            }
        }

        return maxi;
    }
}

public class Longest_Ksum_subarray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter the array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter the target sum k: ");
        int k = sc.nextInt();

        Solution sol = new Solution();
        int result = sol.longestSubarray(arr, k);

        System.out.println("Length of the longest subarray with sum " + k + " is: " + result);

        sc.close();
    }
}
