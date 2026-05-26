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
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHeight = 0;
        int rightHeight = 0;

        if(root->left == nullptr && root->right == nullptr) return 1;

        if(root->left != nullptr) {
            leftHeight = height(root->left) + 1;
        }

        if(root->right != nullptr) {
            rightHeight = height(root->right) + 1;
        }

        return max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diameter = leftHeight + rightHeight;

        int leftDiameter = 0;
        int rightDiameter = 0;

        if(root->left != nullptr) {
            leftDiameter = diameterOfBinaryTree(root->left);
        }

        if(root->right != nullptr) {
            rightDiameter = diameterOfBinaryTree(root->right);
        }

        diameter = max(diameter, leftDiameter);
        diameter = max(diameter, rightDiameter);

        return diameter;

    }
};
