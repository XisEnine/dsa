package Arrays;

public class Linear {
    public static void main(String[] args) {
        int arr[]={12,3,2,13,1,4,2};
        int n = 7;
        int index = -1;
        int t = 13;
        for (int i  = 0; i < n; i++) {
            if(arr[i] == t){
                index = i;
                break;
            }
        }
        System.out.println("Given Index : " + index);
    }
}
