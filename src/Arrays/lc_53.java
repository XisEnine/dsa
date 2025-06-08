package Arrays;

public class lc_53 {
    public static int maxSubArray(int[] nums) {
        int max_sum = nums[0];
        int current_sum = 0;
        for(int i = 0; i < nums.length; i+=1){
            current_sum += nums[i];
            max_sum = Math.max(max_sum,current_sum);
            if(current_sum < 0){
                current_sum  = 0;
            }
        }
        return max_sum;
    }

    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5};
        int res = maxSubArray(arr);
        System.out.println(res);
    }
}
