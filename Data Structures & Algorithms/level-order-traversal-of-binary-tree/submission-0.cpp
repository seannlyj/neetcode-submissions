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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;


        while(!q.empty()) {
            int queueSize = q.size();
            vector<int> nested;

            for(int i = 0; i < queueSize; i++){
                TreeNode* n = q.front();
                q.pop();

                cout<<n->val<<" level: "<<level<<endl;
                nested.push_back(n->val);

                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);

            }
            level++;
            res.push_back(nested);
        }

        return res;
    }
};
