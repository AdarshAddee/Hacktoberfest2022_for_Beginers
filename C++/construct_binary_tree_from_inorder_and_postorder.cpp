/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int index=0;
    TreeNode *recurse(vector<int>&inorder,int low,int high,vector<int>&postorder,int n)
    {
        if(low>high||index<0) return NULL;
        TreeNode *curr=new TreeNode(postorder[index],NULL,NULL);
        int mid=-1;
        for(int i=low;i<=high;i++)
        {
            if(inorder[i]==postorder[index])
            {
                mid=i;
                break;
            }
        }
        index--;
        curr->right=recurse(inorder,mid+1,high,postorder,n);
        curr->left=recurse(inorder,low,mid-1,postorder,n);
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n=postorder.size();
        index=n-1;
        return recurse(inorder,0,n-1,postorder,n);
    }
};