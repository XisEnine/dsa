package Arrays;

public class lc_152 {
    public static int maxProduct(int[] nums) {
        int maxi = Integer.MIN_VALUE;
        int n  = nums.length;
        int suff = 1,pre = 1;
        for(int i = 0; i < n; i+=1){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre *= nums[i];
            suff *= nums[n - i - 1];
            maxi = Math.max(maxi,Math.max(pre,suff));
        }
        return maxi;
    }

    public static void main(String[] args) {
        int arr[] = {2,3,-2,4};
        int res = maxProduct(arr);
        System.out.println(res);
    }
}
