// Contributor: Anjali Singh
// Inorder Traversal in Binary Tree

#include <iostream>
#include <vector>
using namespace std;

// A Binary Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};

// class containing the function to perform inorder traversal
//  and returning a vector containing the answer
class Solution
{
public:
    vector<int> ans;
    vector<int> inorderTraversal(Node *root)
    {
        if (!root)
            return ans;
        helper(root);
        return ans;
    }
    void helper(Node *root)
    {
        if (!root)
            return;
        helper(root->left);
        ans.push_back(root->key);
        helper(root->right);
    }
};

// Utility function creates a new binary tree node with
// given key
Node *newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "\n Inorder traversal of the given tree would be: \n ";
    Solution s;
    vector<int> ans;
    ans = s.inorderTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl
         << endl;
    return 0;
}
