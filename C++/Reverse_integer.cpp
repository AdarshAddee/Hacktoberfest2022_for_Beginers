//https://leetcode.com/problems/reverse-integer/

//code
class Solution {
public:
    int reverse(int x) {
        long int reverse=0;
        while(x!=0){
            int digit=x%10;
            reverse=reverse*10+ digit;
            x=x/10;
        }
        return reverse;
    }
};

//by - khushi marothi
