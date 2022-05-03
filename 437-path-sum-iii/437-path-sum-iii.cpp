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
    void dfs(TreeNode* root,int &targetSum,int &ans,vector<long long>& parent){
        if(root==NULL) return;
        parent.push_back(root->val);
        long long prev_sum=0;
        for(int i=parent.size()-1;i>=0;i--){
            prev_sum+=1ll*parent[i];
            if(prev_sum==targetSum) ans++;
        }
        dfs(root->left,targetSum,ans,parent);
        dfs(root->right,targetSum,ans,parent);
        parent.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        vector<long long> parent;
        dfs(root,targetSum,ans,parent);
        return ans;
    }
};