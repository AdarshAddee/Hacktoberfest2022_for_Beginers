class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>a;
        int count = 0;
        int total = n*m;
        
        int left= 0;
        int top = 0;
        int right = n-1;
        int down = m-1;
        
        while(count<total){
            //starting row
            for(int i=top;count<total && i<=down;i++){
                a.push_back(matrix[left][i]);
                count++;
            }
            left++;
            
            //ending column
            for(int i=left;count<total && i<=right;i++){
                a.push_back(matrix[i][down]);
                count++;
            }
            down--;
            
            //ending row
            for(int i = down;count<total && i>=top;i--){
                a.push_back(matrix[right][i]);
                count++;
            }
            right--;
            
            //starting column
            for(int i = right;count<total && i>=left;i--){
                a.push_back(matrix[i][top]);
                count++;
            }
            top++;
        }
        return a;
    }
};