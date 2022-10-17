//LEETCODE PROBLEM-https://leetcode.com/problems/matrix-diagonal-sum/

//PROBLEM STATEMENT-
//Given a square matrix mat, return the sum of the matrix diagonals.Only include the sum of all the elements on the primary diagonal and all the elements on the 
//secondary diagonal that are not part of the primary diagonal.

//INPUT- { { 8, 2, 13, 4 },{ 9, 16, 17, 8 }, { 1, 22, 3, 14 },{ 15, 6, 17, 8 } }
//OUTPUT-93


//CODE-

import java.util*;
public class Sumofdiagonalelements{
    

    static int diagonalSum(int[][] mat) {
        int sum=0;
        int check=mat.length-1;
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat.length;j++){
                if((i==j)  || (i+j==mat.length-1)){
                    sum+=mat[i][j];
                }
            }
        }
        return sum;
        
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int[][] matrix ={ { 8, 2, 13, 4 },
                        { 9, 16, 17, 8 },
                        { 1, 22, 3, 14 },
                        { 15, 6, 17, 8 } };

        System.out.println("sum of diagnols = " + diagonalSum(matrix));
    }
}
 
