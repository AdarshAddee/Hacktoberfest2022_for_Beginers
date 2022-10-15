// Code : Max data node
// Send Feedback
// Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
// Return null if tree is empty.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
// Output Format :
// The first and only line of output contains the data of the node with largest data in the given tree.
// Constraints:
// Time Limit: 1 sec
// Sample Input 1:
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output 1:
// 50

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

#include "solution.h"

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int> *max=root;

    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *get_max=maxDataNode(root->children[i]);
        if(get_max->data>max->data){
            max=get_max;
        }
    }
    return max;
}


int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);

    if (root != NULL) {
        cout << ans->data;
    }
}
