// C++ program to find all LCS of two strings in
// sorted order.
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

// length of lcs
int lcslen = 0;

// dp matrix to store result of sub calls for lcs
int dp[MAX][MAX];

// A memoization based function that returns LCS of
// str1[i..len1-1] and str2[j..len2-1]
int lcs(string str1, string str2, int len1, int len2,
									int i, int j)
{
	int &ret = dp[i][j];

	// base condition
	if (i==len1 || j==len2)
		return ret = 0;

	// if lcs has been computed
	if (ret != -1)
		return ret;

	ret = 0;

	// if characters are same return previous + 1 else
	// max of two sequences after removing i'th and j'th
	// char one by one
	if (str1[i] == str2[j])
		ret = 1 + lcs(str1, str2, len1, len2, i+1, j+1);
	else
		ret = max(lcs(str1, str2, len1, len2, i+1, j),
				lcs(str1, str2, len1, len2, i, j+1));
	return ret;
}

// Function to print all routes common sub-sequences of
// length lcslen
void printAll(string str1, string str2, int len1, int len2,char data[], int indx1, int indx2, int currlcs)
{
	if (currlcs == lcslen)
	{
		data[currlcs] = '\0';
		puts(data);
		return;
	}
	if (indx1==len1 || indx2==len2)
		return;

	for (char ch='a'; ch<='z'; ch++)
	{
		bool done = false;
		for (int i=indx1; i<len1; i++)
		{
			if (ch==str1[i])
			{
			for (int j=indx2; j<len2; j++)
			{
				if (ch==str2[j] &&
				dp[i][j] == lcslen-currlcs)
				{
				data[currlcs] = ch;
				printAll(str1, str2, len1, len2, data, i+1, j+1, currlcs+1);
				done = true;
				break;
				}
			}
			}
			if (done)
				break;
		}
	}
}

// This function prints all LCS of str1 and str2
// in lexicographic order.
void prinlAllLCSSorted(string str1, string str2)
{
	// Find lengths of both strings
	int len1 = str1.length(), len2 = str2.length();

	// Find length of LCS
	memset(dp, -1, sizeof(dp));
	lcslen = lcs(str1, str2, len1, len2, 0, 0);

	// Print all LCS using recursive backtracking
	// data[] is used to store individual LCS.
	char data[MAX];
	printAll(str1, str2, len1, len2, data, 0, 0, 0);
}

// Driver program to run the case
int main()
{
	string str1 = "abcabcaa", str2 = "acbacba";
	prinlAllLCSSorted(str1, str2);
	return 0;
}
