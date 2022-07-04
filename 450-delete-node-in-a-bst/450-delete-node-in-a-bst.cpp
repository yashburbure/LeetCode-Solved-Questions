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
        TreeNode* p=NULL;
        TreeNode* q=root;
        while(q){
            if(q->val==key){
                if(q->left && q->right){
                    TreeNode* temp=q->right;
                    while(temp->left) temp=temp->left;
                    q->val=temp->val;
                    q->right=deleteNode(q->right,temp->val);
                }
                else if(q->left){
                    if(p){
                        if(p->right==q){
                            p->right=q->left;
                        }
                        else{
                            p->left=q->left;
                        }    
                    }
                    else{
                        root=q->left;
                    }
                }
                else if(q->right){
                    if(p){
                        if(p->right==q){
                            p->right=q->right;
                        }
                        else{
                            p->left=q->right;
                        }   
                    }
                    else{
                        root=q->right;
                    }
                }
                else{
                    if(p){
                        if(p->left==q){
                            p->left=NULL;
                        }
                        else{
                            // cout<<p->val<<endl;
                            p->right=NULL;
                        }
                    }
                    else{
                        root=NULL;
                    }
                }
                break;
            }
            p=q;
            if(q->val>key){
                q=q->left;
            }
            else{
                q=q->right;
            }
        }
        return root;
    }
};