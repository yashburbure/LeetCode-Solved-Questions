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
string ans;
void preorder(TreeNode*& root){
    if(!root) return;
    ans+=to_string(root->val);
    if(root->left && root->right){
        ans.push_back('(');
        preorder(root->left);
        ans.push_back(')');
        ans.push_back('(');
        preorder(root->right);
        ans.push_back(')');   
    }
    else if(root->left){
        ans.push_back('(');
        preorder(root->left);
        ans.push_back(')');
    }
    else if(root->right){
        ans.push_back('(');
        preorder(root->left);
        ans.push_back(')');
        ans.push_back('(');
        preorder(root->right);
        ans.push_back(')'); 
    }
}
class Solution {
public:
    string tree2str(TreeNode* root) {
        ans.clear();
        preorder(root);
        return ans;
    }
};