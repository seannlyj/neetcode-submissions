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

// A good node is defined by:
// From root to my node, am i the biggest value? If so, I am a good node.

class Solution {
public:
    void dfs(int maxVal, int& goodNodes, TreeNode* node){
        if(node == nullptr) return;

        cout<<"Processing Node " << node->val << endl;
        cout<<"maxVal >= node->val : " << maxVal << " >= "<<node->val<<endl;
        if(node->val >= maxVal)
        {
            cout<<"GoodNode++"<<endl;
            goodNodes++;
            maxVal = node->val;
        }
        cout<<endl;

        if(node->left) dfs(maxVal, goodNodes, node->left);
        if(node->right) dfs(maxVal, goodNodes, node->right);
    }

    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int goodNodes = 0;
        int maxVal = root->val;

        dfs(maxVal, goodNodes, root);

        return goodNodes;
    }
};
