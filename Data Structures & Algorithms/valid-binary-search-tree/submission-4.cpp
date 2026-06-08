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
    bool isBST(TreeNode* node, int min, int max){
        if(node == nullptr) return true;

        if(node->val < min || node->val > max) return false;

        return isBST(node->left, min, node->val - 1) && isBST(node->right, node->val + 1, max);
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, -INT_MAX, INT_MAX);
    }
};
