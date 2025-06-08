package Arrays;

public class CheckSort{
    public static void main(String[] args) {
        int arr[] = {1,2,3,6,5};
        int n = 5;
        System.out.println("Result : " + isSorted(n,arr));
    }

    public static int isSorted(int n, int []arr) {
        // Write your code here.
        for(int i = 1; i < n; i+=1){
            if(arr[i] < arr[i-1]) return 0;
        }
        return 1;
    }
}
