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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;

        if(p && !q) return false;
        if(!p && q) return false;

        queue<TreeNode*> pqueue;
        pqueue.push(p);

        queue<TreeNode*> qqueue;
        qqueue.push(q);

        while(!pqueue.empty() && !qqueue.empty()){

            TreeNode* pnode = pqueue.front();
            pqueue.pop();

            TreeNode* qnode = qqueue.front();
            qqueue.pop();

            //process conditions
            //if pleft exists and qleft null OR pleft null and qleft exists
            if((pnode->left != nullptr && qnode->left == nullptr) || (pnode->left == nullptr && qnode->left != nullptr)) {
                return false;
            }

            //if pright exists and qright null OR pright null and qright exists
            if((pnode->right != nullptr && qnode->right == nullptr) || (pnode->right == nullptr && qnode->right != nullptr)){
                return false;
            }

            // if they pass these conditions, then that must mean they have the same children
            // check where this pnode and qnode has the same value
            if(pnode->val != qnode->val)
                return false;


            if(pnode->left) pqueue.push(pnode->left);
            if(qnode->left) qqueue.push(qnode->left);

            if(pnode->right) pqueue.push(pnode->right);
            if(qnode->right) qqueue.push(qnode->right);

        }

        return true;
    }
};
