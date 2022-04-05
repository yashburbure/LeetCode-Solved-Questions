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
    void inorder(TreeNode* root,vector<int>& inod){
        if(!root) return;
        inorder(root->left,inod);
        inod.push_back(root->val);
        inorder(root->right,inod);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inod;
        inorder(root,inod);
        return inod[k-1];
    }
};