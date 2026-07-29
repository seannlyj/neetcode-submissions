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

        // just bfs
        queue<TreeNode*> s;
        s.push(root);

        int depth = 0;
        int currlevelnodes = 0;

        while(!s.empty()){
            currlevelnodes = s.size();
            for(int i = 0; i < currlevelnodes; i++){
                TreeNode* n = s.front(); s.pop();

                if(n->left) s.push(n->left);
                if(n->right) s.push(n->right);
            }
            depth++;

        }
        return depth;

    }
};
