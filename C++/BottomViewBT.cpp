// Bottom View Of Binary Tree

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

struct Node
{
    int data;
    Node *left, *right;

    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};

vector<int> bottomView(Node *root)
{
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            Node *node = temp.first;
            int line = temp.second;
            mp[line] = node->data;
            if(node->left)
                q.push({node->left, line-1});
            if(node->right)
                q.push({node->right, line+1});
        }
        
        for(auto x: mp)
                ans.push_back(x.second);
                
        return ans;
}

signed main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    vector<int> bottom_elements;
    bottom_elements = bottomView(root);
    for(auto x : bottom_elements)
          cout<<x<<" ";
    return 0;
}
