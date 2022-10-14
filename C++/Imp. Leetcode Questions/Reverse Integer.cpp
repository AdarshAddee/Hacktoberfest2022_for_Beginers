// https://leetcode.com/problems/reverse-integer/


class Solution {
public:
    int reverse(int x) {
        int num = 0;
        int digit;
        
        
        while(x!=0){
            digit = x % 10;
            
            if((num< INT_MIN/10) || (num> INT_MAX/10)){
                return 0;
            }
            
            num = (num*10) +digit;
            x = x /10;
        }
        
        cout<< num;
        
        return num;
    }
};