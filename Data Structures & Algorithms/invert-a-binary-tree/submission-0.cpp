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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            
            for(int i = 0; i < q.size(); i++){
                TreeNode* node = q.front();
                q.pop();

                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
        }

        return root;
    }
};
