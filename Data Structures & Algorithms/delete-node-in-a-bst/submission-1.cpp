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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(root == nullptr) return root;

        if(root->val == key){
            //if there is only one child
            if(root->left && !root->right){
                return root->left;
            } 
            else if(!root->left && root->right){ 
                return root->right;
            } 
            // there are two childs
            else if(root->left && root->right){
                TreeNode* curr = root->right;
                //go into left of root->right to get smallest value
                while(curr->left != nullptr){
                    curr = curr->left;
                }
                root->val = curr->val;
                root->right = deleteNode(root->right, curr->val);
                return root;
                
            } else {
                return nullptr;
            }
            
        }

        // recursion
        if(key < root->val) root->left = deleteNode(root->left, key);
        if(key > root->val) root->right = deleteNode(root->right, key);
        
        return root;
    }
};