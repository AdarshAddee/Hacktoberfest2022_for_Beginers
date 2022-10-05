class Solution {
public:
    double myPow(double x, int n) {
        
         double ans=1.0;
        
        for(int i= abs(n);i>0;i/=2){
           if(i & 1) 
            ans*=x;                          
            x*=x;
        }
        
       if(n<0){
            return 1/ans;
        }else if(n==0){
            return 1;
        }else{
            return ans;
        }
    
        
        
    }
};
