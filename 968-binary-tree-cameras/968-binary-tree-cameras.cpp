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
    int dfs(TreeNode*& root,bool parent,bool pcol,string path,
             map<pair<string,pair<bool,bool>>,int>& dp){
        if(!root){
            return 0;
        }
        if(dp.find({path,{parent,pcol}})!=dp.end()) return dp[{path,{parent,pcol}}];
        int ans=1e8;
        if(parent){
            if(pcol){
                ans=min(ans,dfs(root->left,1,0,path+'L',dp)+dfs(root->right,1,0,path+'R',dp));
                ans=min(ans,1+dfs(root->left,1,1,path+'L',dp)+dfs(root->right,1,1,path+'R',dp));
            }
            else{
                ans=min(ans,1+dfs(root->left,1,1,path+'L',dp)+dfs(root->right,1,1,path+'R',dp));
                if(root->left && root->right){
                    ans=min(ans,dfs(root->left,0,0,path+'L',dp)+dfs(root->right,1,0,path+'R',dp));
                    ans=min(ans,dfs(root->left,1,0,path+'L',dp)+dfs(root->right,0,0,path+'R',dp));
                }
                else if(root->left){
                    ans=min(ans,dfs(root->left,0,0,path+'L',dp));
                }
                else if(root->right){
                    ans=min(ans,dfs(root->right,0,0,path+'R',dp));
                }
            }
        }
        else{
            ans=min(ans,1+dfs(root->left,1,1,path+'L',dp)+dfs(root->right,1,1,path+'R',dp));
        }
        return dp[{path,{parent,pcol}}]=ans;
    }
    int minCameraCover(TreeNode* root) {
        map<pair<string,pair<bool,bool>>,int> dp;
        string path="";
        int ans=dfs(root,1,0,path,dp);
        return ans;
    }
};