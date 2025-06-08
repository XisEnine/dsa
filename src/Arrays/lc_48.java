package Arrays;

public class lc_48 {
    static void reverse(int[] matrix, int start, int end) {
        while (start < end) {
            int t = matrix[start];
            matrix[start] = matrix[end];
            matrix[end] = t;
            start += 1;
            end -= 1;
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };

        rotate(matrix);

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void rotate(int[][] matrix) {

        for (int i = 0; i < matrix.length; i += 1) {
            for (int j = 0; j < matrix[0].length; j += 1) {
                if (i != j && j > i) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }

        // reversing each row
        for (int i = 0; i < matrix.length; i += 1) {
            reverse(matrix[i], 0, matrix[i].length - 1);
        }
    }
}
