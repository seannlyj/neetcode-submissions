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
private:
    bool balanced = true;
public:
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        int diff = abs(left-right);
        if(diff > 1)
            balanced = false;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return balanced;
        dfs(root);
        return balanced;
    }
};
