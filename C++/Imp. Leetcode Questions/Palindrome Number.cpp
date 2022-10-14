// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        long long int rev=0;
        int num=x;
        while(x>0)
        {
            int rem=x%10;
            rev=(rev*10)+rem;
            x=x/10;
        }
        if(rev==num)
            return true;
        else
            return false;
    }
};