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
    TreeNode* successor(TreeNode *root){
        while(root->left) root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left&&root->right){
                TreeNode* succ=successor(root->right);
                root->right=deleteNode(root->right,succ->val);
                root->val=succ->val;
                return root;
            }
            else if(root->right){
                // TreeNode* del=root;
                // delete del;
                return root->right;
            }
            else if(root->left){
                // TreeNode* del=root;
                // delete del;
                return root->left;
            }
            return NULL;
        }
        return root;
    }
};