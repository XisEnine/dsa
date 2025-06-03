package ArraysAndHashing;

public class LargestEle {
    public static void main(String[] args) {
        int arr[] = {1,2,3,45,3,8};
        int res = largest(arr,6);
        System.out.println(res);
    }
    static int largest(int arr[],int size){
        int l = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > l) l = arr[i];
        }
        return l;
    }
}
