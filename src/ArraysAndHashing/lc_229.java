package ArraysAndHashing;

import java.util.ArrayList;
import java.util.List;

public class lc_229 {
    public static List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        int candidate1 = Integer.MIN_VALUE, candidate2 = Integer.MIN_VALUE, count_1 = 0, count_2 = 0;

        for (int i = 0; i < n; i += 1) {
            if (count_1 == 0 && candidate2 != nums[i]) {
                count_1 = 1;
                candidate1 = nums[i];
            } else if (count_2 == 0 && candidate1 != nums[i]) {
                count_2 = 1;
                candidate2 = nums[i];
            } else if (nums[i] == candidate1) {
                count_1 += 1;
            } else if (nums[i] == candidate2) {
                count_2 += 1;
            } else {
                count_1 -= 1;
                count_2 -= 1;
            }
        }
        List<Integer> ans = new ArrayList<>();
        int cnt1 = 0, cnt2 = 0;
        int mini = (int) (n / 3) + 1;
        for (int num : nums) {
            if (num == candidate1)
                cnt1++;
            if (num == candidate2)
                cnt2++;
        }
        if (cnt1 >= mini)
            ans.add(candidate1);
        if (cnt2 >= mini)
            ans.add(candidate2);
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {1,2};
        List<Integer> ans = majorityElement(nums);
        for(int i : ans){
            System.out.print(i + " ");
        }
    }
}
