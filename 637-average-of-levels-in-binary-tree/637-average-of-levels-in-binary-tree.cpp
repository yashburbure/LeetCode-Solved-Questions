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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> average;
        queue<TreeNode*> q;
        q.push(root);
        long long n,sum,i;
        TreeNode* tp;
        while(q.size()){
            n=q.size();
            sum=0;
            for(i=0;i<n;i++){
                tp=q.front();
                q.pop();
                sum+=tp->val;
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
            }
            average.push_back(sum/(n*1.0));
        }
        return average;
    }
};