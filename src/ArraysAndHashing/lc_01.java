package ArraysAndHashing;

import java.util.HashMap;

public class lc_01 {
    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> mpp = new HashMap();

        for(int i = 0; i < nums.length; i += 1){
            int rem = target - nums[i];
            if(mpp.containsKey(rem)){
                int arr[] = {mpp.get(rem),i};
                return arr;
            }
            mpp.put(nums[i],i);
        }
        return new int[] { -1, -1 };
    }

    public static void main(String[] args) {
        int res[] = new int[2];
        int arr[] = {2,7,11,15};
        int t = 9;
        res = twoSum(arr,t);
        for(int i = 0; i  < 2; i +=1){
            System.out.println(res[i] + " ");
        }
    }
}
