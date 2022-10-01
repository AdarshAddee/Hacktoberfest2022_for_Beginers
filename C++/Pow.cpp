//https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        if (n == INT_MAX) 
            return x;
        else if (n == INT_MIN) 
            return (x == 1 || x == -1) ? 1 : 0;
        if(n<0) x=1/x, n*=-1;
        for(int i=1; i<=n;i++){
            res=res*x;
        }
        return res;
    }
};

//by - khushi marothi
