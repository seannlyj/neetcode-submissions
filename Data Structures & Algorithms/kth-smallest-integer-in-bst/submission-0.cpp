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
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;

        //BFS traversal and add everything to a heap?
        priority_queue<int, vector<int>, greater<int>> maxheap;

        //iterative bfs
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            maxheap.push(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        for(int i = 1; i < k; i++){
            maxheap.pop();
        }

        return maxheap.top();
    }
};
