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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp=root;
        TreeNode* par=NULL;
        while(temp&&temp->val!=key){
            par=temp;
            if(temp->val<key) temp=temp->right;
            else temp=temp->left;
        }
        if(!temp) return root;
        if(temp->left&&temp->right){
            TreeNode* succ=temp->right;
            TreeNode* upp=temp;
            while(succ->left){
                upp=succ;
                succ=succ->left;
            }
            if(temp==upp){
                if(succ->right){
                    upp->right=succ->right;
                }
                else{
                    upp->right=NULL;
                }
            }
            else{
                if(succ->right){
                    upp->left=succ->right;
                }
                else{
                    upp->left=NULL;
                }
            }
            temp->val=succ->val;
            return root;
        }
        else if(temp->left||temp->right){
            if(par){
                if(temp->left){
                    if(par->left==temp){
                        par->left=temp->left;
                    }
                    else{
                        par->right=temp->left;
                    }
                }
                else{
                    if(par->right==temp){
                        par->right=temp->right;
                    }
                    else par->left=temp->right;
                }
                return root;
            }
            else{
                if(temp->left){
                    root=temp->left;
                }
                else{
                    root=temp->right;
                }
                return root;
            }
        }
        else{
            if(par){
                TreeNode* del;
                if(par->val<key){
                    del=par->right;
                    par->right=NULL;
                } 
                else{
                    del=par->left;
                    par->left=NULL;
                }
                return root;
            }
            return NULL;
        }
    }
};