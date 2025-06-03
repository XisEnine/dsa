package ArraysAndHashing;

public class lc_73 {
    //to mark whole column as 0
    static void markRow(int[][] mat, int row, int col, int i) {
        for (int j = 0; j < col; j += 1) {
            if (mat[i][j] != 0) {
                mat[i][j] = -1;
            }
        }
    }

    //to mark whole column as 0
    static void markCol(int[][] mat, int row, int col, int j) {
        for (int i = 0; i < row; i += 1) {
            if (mat[i][j] != 0) {
                mat[i][j] = -1;
            }
        }
    }

    static void setZero(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;

        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, row, col, i);
                    markCol(matrix, row, col, j);
                }
            }
        }

        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    static void print(int[][] mat){
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {{1,1,1},{1,0,1},{1,1,1}};
        System.out.println("Original matrix:");
        print(matrix);
        setZero(matrix);
        System.out.println("After setting zeros:");
        print(matrix);
    }
}