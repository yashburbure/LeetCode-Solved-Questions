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
    vector<vector<int>> verticalTraversal(TreeNode*& root) {
        map<int,vector<pair<int,int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        mp[0].push_back({root->val,0});
        pair<TreeNode*,pair<int,int>> tp;
        while(q.size()){
            tp=q.front();
            q.pop();
            if(tp.first->left){
                mp[tp.second.first-1].push_back({tp.first->left->val,tp.second.second+1});
                q.push({tp.first->left,{tp.second.first-1,tp.second.second+1}});
            }
            if(tp.first->right){
                mp[tp.second.first+1].push_back({tp.first->right->val,tp.second.second+1});
                q.push({tp.first->right,{tp.second.first+1,tp.second.second+1}});
            }
        }
        vector<vector<int>> ans;
        vector<int> curr;
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end(),[&](pair<int,int>& a,pair<int,int>& b){
                if(a.second!=b.second) return a.second<b.second;
                return a.first<=b.first;
            });
            for(auto &it2:it.second){
                curr.push_back(it2.first);
            }
            ans.push_back(curr);
            curr.clear();
        }
        return ans;
    }
};