package ArraysAndHashing;

public class SecondLargest {
    public static void main(String[] args) {
        int arr[] = {1,2,3,45,3,8,63};
        int res = second(arr,7);
        System.out.println(res);
    }
    static int second(int arr[],int n){
        int l = arr[0];
        int sl = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if(arr[i] > l){
                sl = l;
                l = arr[i];
            }else if(arr[i] < l && arr[i] > sl) sl = arr[i];
        }
        return sl;
    }
}
