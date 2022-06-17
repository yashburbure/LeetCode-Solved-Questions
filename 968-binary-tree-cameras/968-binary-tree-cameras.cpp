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
    int dfs(TreeNode*& root,bool parent,bool pcol,string& path,
             map<pair<string,pair<bool,bool>>,int>& dp){
        if(!root){
            return 0;
        }
        if(dp.find({path,{parent,pcol}})!=dp.end()) return dp[{path,{parent,pcol}}];
        string s1=path+'L';
        string s2=path+'R';
        int ans=1e8;
        if(parent){
            if(pcol){
                ans=min(ans,dfs(root->left,1,0,s1,dp)+dfs(root->right,1,0,s2,dp));
                ans=min(ans,1+dfs(root->left,1,1,s1,dp)+dfs(root->right,1,1,s2,dp));
            }
            else{
                ans=min(ans,1+dfs(root->left,1,1,s1,dp)+dfs(root->right,1,1,s2,dp));
                if(root->left && root->right){
                    ans=min(ans,dfs(root->left,0,0,s1,dp)+dfs(root->right,1,0,s2,dp));
                    ans=min(ans,dfs(root->left,1,0,s1,dp)+dfs(root->right,0,0,s2,dp));
                }
                else if(root->left){
                    ans=min(ans,dfs(root->left,0,0,s1,dp));
                }
                else if(root->right){
                    ans=min(ans,dfs(root->right,0,0,s2,dp));
                }
            }
        }
        else{
            ans=min(ans,1+dfs(root->left,1,1,s1,dp)+dfs(root->right,1,1,s2,dp));
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