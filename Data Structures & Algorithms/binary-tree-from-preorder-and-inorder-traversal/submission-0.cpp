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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd){
        if(preStart > preEnd) return nullptr;

        // Get the root value and the index of it in the Inorder array
        int nodeVal = preorder[preStart];
        int inIndex;
        for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == nodeVal) inIndex = i;
        }

        TreeNode* node = new TreeNode(nodeVal);

        int leftSize = inIndex - inStart;
        node->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, inIndex - 1);
        node->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, inIndex + 1, inEnd);

        return node;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
