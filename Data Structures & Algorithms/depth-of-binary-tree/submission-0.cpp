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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});

        int result = 1;

        while(!s.empty()){
            pair<TreeNode*, int> top = s.top();
            s.pop();

            TreeNode* node = top.first;
            int depth = top.second;

            if(node->left != nullptr) s.push({node->left, depth + 1});
            if(node->right != nullptr) s.push({node->right, depth + 1});

            result = max(result, depth);
        }

        return result;
    }
};
