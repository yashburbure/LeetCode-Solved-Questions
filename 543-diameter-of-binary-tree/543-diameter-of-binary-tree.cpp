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
        if(root==NULL) return 0;
        return max(1+height(root->left),1+height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==0) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return max({lh+rh,diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
    }
};