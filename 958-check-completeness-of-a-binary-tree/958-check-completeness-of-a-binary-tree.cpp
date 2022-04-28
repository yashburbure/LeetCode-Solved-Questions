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
    int find_ht(TreeNode* root){
        int lh=0;
        int rh=0;
        if(root->left) lh=1+find_ht(root->left);
        if(root->right) rh=1+find_ht(root->right);
        return max(lh,rh);
    }
    bool isCompleteTree(TreeNode* root) {
        int height=find_ht(root);
        int curr_level=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            if(curr_level>=height-1){
                int flag=1;
                for(int i=0;i<n;i++){
                    TreeNode* curr=q.front();
                    q.pop();
                    if(flag){
                        if(curr->left && curr->right){
                            flag=1;
                        }
                        else if(curr->left) flag=0;
                        else if(curr->right) return 0;
                        else flag=0;
                    }
                    else{
                        if(curr->left || curr->right) return 0;
                    }
                }
            }
            else{
                for(int i=0;i<n;i++){
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr->left && curr->right){
                        q.push(curr->left);
                        q.push(curr->right);
                    }
                    else return 0;
                }
            }
            curr_level++;
        }
        return 1;
    }
};