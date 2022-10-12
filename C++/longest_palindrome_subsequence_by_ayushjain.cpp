
// Name : Ayush jain
// Github username  Ayushjain373
// Start coding: 10/12/2022
// Problem Statement: Longest Palindromic Subsequence

// A palindromic string is a string that is equal to its reverse. For example: “nitin” is a palindromic string. Now the question states to find the length of the longest palindromic subsequence of a string. It is that palindromic subsequence of the given string with the greatest length.

// Example Str = "bbbab"
// output = "bbbb"
// There can be many subsequences like “b”, “ba”,”bbb” but “bbbb” is the subsequence that is a palindrome and has the greatest length.

// We need to print the length of the longest palindromic subsequence.


// Approach
// Pre-req: Longest Common Subsequence



// Intuition:

// Let us say that we are given the following string.


// The longest palindromic subsequence will be: “babcbab”.

// What is special about this string is that it is palindromic (equal to its reverse) and of the longest length.

// Now let us write the reverse of str next to it and please think about the highlighted characters.


// If we look closely at the highlighted characters, they are nothing but the longest common subsequence of the two strings.

// Now, we have taken the reverse of the string for the following two reasons:

// The longest palindromic subsequence being a palindrome will remain the same when the entire string is reversed.
// The length of the palindromic subsequence will also remain the same when the entire string is reversed.
// From the above discussion we can conclude:

// The longest palindromic subsequence of a string is the longest common subsequence of the given string and its reverse.

// Approach:

// The algorithm is stated as follows:

// We are given a string (say s), make a copy of it and store it( say string t).
// Reverse the original string s.
// Find the longest common subsequence 

// Code

#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
}

int longestPalindromeSubsequence(string s){
    string t = s;
    reverse(s.begin(),s.end());
    return lcs(s,t);
}

int main() {

  string s= "bbabcbcab";
                                 
  cout<<"The Length of Longest Palindromic Subsequence is "<<
  longestPalindromeSubsequence(s);
}

// Output: The Length of Longest Palindromic Subsequence is 7

// Time Complexity: O(N*N)

// Reason: There are two nested loops

// Space Complexity: O(N*N)

// Reason: We are using an external array of size ‘(N*N)’. Stack Space is eliminated.