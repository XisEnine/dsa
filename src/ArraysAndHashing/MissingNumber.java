package ArraysAndHashing;

public class MissingNumber {
    public static void main(String[] args) {
        int arr[]={9,6,4,2,3,5,7,0,1};
        int n = arr.length;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        int missing_number = (n*(n+1)/2) - sum;
        System.out.println(missing_number);
    }
}
