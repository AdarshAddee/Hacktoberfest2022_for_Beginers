// Github username: ritwik009
// Aim: Contributing to DSA code base
// Date: 14/10/22

// Problem name: Binary Tree Level Order Traversal
// Problem link: https://leetcode.com/problems/binary-tree-level-order-traversal/

// DFS with pre-order
	// just need to store the level in state between recursive calls
	void dfs_pre(vector<vector<int>> &res, TreeNode *node, int level) {
        if (!node) return;
        
        if (res.size() <= level) {
            res.push_back(vector<int>());
        }
        res[level].push_back(node->val);
        
        dfs_pre(res, node->left, level + 1);
        dfs_pre(res, node->right, level + 1);
    } 
    
	// Class BFS with added tracking for level to push back to result
    vector<vector<int>> bfs(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root) q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            res.push_back(vector<int>());
            int q_size = q.size();
            
            for (int i = 0; i < q_size; i++) {
                TreeNode *node = q.front();
                q.pop();
                
                res[level].push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        
        return res;
    }