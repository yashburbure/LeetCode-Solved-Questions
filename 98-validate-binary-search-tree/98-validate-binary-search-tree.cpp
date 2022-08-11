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
    vector<int> InorderPath;
    void inorder(TreeNode*& root){
        if(!root) return ;
        inorder(root->left);
        InorderPath.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=1;i<InorderPath.size();i++){
            if(InorderPath[i-1]>=InorderPath[i]) return 0;
        }
        return 1;
    }
};