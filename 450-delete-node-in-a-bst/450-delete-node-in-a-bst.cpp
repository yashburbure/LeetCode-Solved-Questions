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
    TreeNode* deleteNode(TreeNode*& root, int &key) {
        if(!root){
            return NULL;
        }
        if(root->val==key){
            if(root->left && root->right){
                TreeNode* temp=root->right;
                while(temp->left) temp=temp->left;
                root->right=deleteNode(root->right,temp->val);
                root->val=temp->val;
            }
            else if(root->left){
                TreeNode* lef=root->left;
                return lef;
            }
            else if(root->right){
                TreeNode* rig=root->right;
                return rig;
            }
            else{
                return NULL;
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};