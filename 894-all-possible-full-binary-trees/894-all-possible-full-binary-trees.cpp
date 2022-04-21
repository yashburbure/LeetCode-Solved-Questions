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
    unordered_map<int,vector<TreeNode*>> dp;
    vector<TreeNode*> construct_BT(int n){
        if(dp.find(n)!=dp.end()) return dp[n];
        vector<TreeNode*> ans;
        if(n==1){
            TreeNode* nn=new TreeNode(0);
            ans.push_back(nn);
            return ans;
        }
        for(int i=1;i<(n-1);i++){
            vector<TreeNode*> leftbt=construct_BT(i);
            vector<TreeNode*> rightbt=construct_BT(n-1-i);
            for(int j=0;j<leftbt.size();j++){
                for(int k=0;k<rightbt.size();k++){
                    TreeNode* nn=new TreeNode(0);
                    nn->left=leftbt[j];
                    nn->right=rightbt[k];
                    ans.push_back(nn);
                }
            }
        }
        return dp[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        ans=construct_BT(n);
        return ans;
    }
};