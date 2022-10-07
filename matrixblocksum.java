class Solution {
    public int get(int[][] mat,int i,int j,int k){
        int rmin = i-k>=0?i-k:0;
        int rmax = i+k<mat.length?i+k:mat.length-1;
        int cmin = j-k>=0?j-k:0; 
        int cmax = j+k<mat[0].length?j+k:mat[0].length-1; 
        int sum = 0;
        for (int r = rmin; r <= rmax; r++) {
            for (int c = cmin; c <= cmax; c++) {
                sum += mat[r][c];
            }
        }
        return sum;
    }
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int[][] ans = new int[mat.length][mat[0].length];
        for(int i = 0;i<mat.length;i++){
            for(int j = 0;j<mat[0].length;j++){
                ans[i][j] = get(mat,i,j,k);
            }
        }
        return ans;
    }
}
