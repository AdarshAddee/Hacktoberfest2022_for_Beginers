#include<bits/stdc++.h>
using namespace std;
struct Node {
	int key;
	Node *left, *right;
	Node (int k)
	{
		key = k;
		left = right = NULL;
	}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        int i=1;
        while(!q.empty()){
            int size = q.size();
            ans.push_back(vector<int>(size,0));
            for(int j=0;j<size;j++){
                TreeNode* node = q.front();
                q.pop();
                if(i%2!=0){
                    ans.back()[j]=node->val;
                }
                else{
                    ans.back()[size-j-1] = node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            i++;
        }
        return ans;
    }


int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(20);
	root->right->right = new Node(60);
  
  vector<vector<int>>res = zigzagLevelOrder(root);
  
  for(auto& i:res){
    cout<<"[";
    for(auto& j:i){
      cout<<j<<" ";
    }
    cout<<"]"<<endl;
  }
  
}
