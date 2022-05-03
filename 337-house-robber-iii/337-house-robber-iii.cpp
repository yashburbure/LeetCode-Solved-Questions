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
    unordered_map<string,int> mp;
    int dfs(TreeNode* root,string s){
        if(root==NULL) return 0;
        if(mp.find(s)!=mp.end()) return mp[s];
        if(root->left && root->right){
            string s1=s+"LL";
            string s2=s+"LR";
            string s3=s+"RL";
            string s4=s+"RR";
            int ans=root->val;
            ans+=dfs(root->left->left,s1);
            ans+=dfs(root->left->right,s2);
            ans+=dfs(root->right->left,s3);
            ans+=dfs(root->right->right,s4);
            int ans2=dfs(root->left,s+'L')+dfs(root->right,s+'R');
            return mp[s]=max(ans2,ans);
        }
        else if(root->left || root->right){
            if(root->left){
                string s1=s+"LL";
                string s2=s+"LR";
                int ans=root->val;
                ans+=dfs(root->left->left,s1);
                ans+=dfs(root->left->right,s2);
                int ans2=dfs(root->left,s+'L');
                return mp[s]=max(ans2,ans);
            }
            else{
                string s3=s+"RL";
                string s4=s+"RR";
                int ans=root->val;
                ans+=dfs(root->right->left,s3);
                ans+=dfs(root->right->right,s4);
                int ans2=dfs(root->right,s+'R');
                return mp[s]=max(ans,ans2);
            }
        }
        else{
            return mp[s]=root->val;
        }
    }
    int rob(TreeNode* root) {
        int ans=dfs(root,"");
        return ans;
    }
};