package Arrays;

public class lc_88 {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
         int i = m - 1,j = n - 1, k = m + n - 1;
         while(j >= 0 && i >= 0){
             if(nums2[j] > nums1[i]){
                 nums1[k--] = nums2[j--];
             }else{
                 nums1[k--] = nums1[i--];
             }
         }
         while(j >= 0){
             nums1[k--] = nums2[j--];
         }
    }
    public static void main(String[] args) {
        int[] nums1 = {1,2,3,0,0,0};
        int m = 3;
        int[] nums2 = {2,5,6};
        int n = 3;
        merge(nums1,m,nums2,n);
        for(int nums : nums1){
            System.out.print(nums + " ");
        }
    }
}
