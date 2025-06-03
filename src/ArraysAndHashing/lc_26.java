package ArraysAndHashing;

public class lc_26 {
    public static void main(String[] args) {
		int arr[] = {0,0,1,1,1,2,2,3,3,4};
        int i = 0;
        for (int j = 0; j < arr.length; j++) {
            if(arr[i] != arr[j]) i+=1;
            arr[i] = arr[j];
        }
        i+=1;
        System.out.println(i);
    }
}
