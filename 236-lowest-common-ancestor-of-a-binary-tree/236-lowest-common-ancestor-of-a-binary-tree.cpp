/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode*& root, TreeNode*& p, TreeNode*& q) {
        if(root==NULL) return root;
        if(root==p || root==q){
            return root;
        }
        TreeNode* left_ans=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_ans=lowestCommonAncestor(root->right,p,q);
        if(left_ans&&right_ans){
            return root;
        }
        else if(left_ans) return left_ans;
        return right_ans;
    }
};