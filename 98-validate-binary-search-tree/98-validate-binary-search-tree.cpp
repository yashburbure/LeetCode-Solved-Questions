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
        if(!root) return ;
        inorder(root->left,inod);
        inod.push_back(root->val);
        inorder(root->right,inod);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inod;
        inorder(root,inod);
        for(int i=1;i<inod.size();i++){
            if(inod[i-1]>=inod[i]) return 0;
        }
        return 1;
    }
};