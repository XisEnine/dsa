package Arrays;

public class lc_169 {
    public static int majorityElement(int[] nums) {
        int ans = nums[0];
        int count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == ans) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    ans = nums[i];
                    count = 1;
                }
            }
        }

        //verifying
        int check = 0;
        for(int num : nums){
            if(num == ans) check++;
        }
        if(check > nums.length/2) return ans;
        return -1;
    }
    public static void main(String[] args) {
        int[] nums = {2,2,1,1,1,2,2};
        int res = majorityElement(nums);
        System.out.println(res);
    }
}
