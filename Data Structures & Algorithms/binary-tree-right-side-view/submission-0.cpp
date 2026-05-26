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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if(root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int queueSize = q.size();
            for(int i = 0; i < queueSize; i++){
                TreeNode* n = q.front();
                q.pop();

                if(i + 1 == queueSize)
                    res.push_back(n->val);

                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }

        }

        return res;
    }
};
