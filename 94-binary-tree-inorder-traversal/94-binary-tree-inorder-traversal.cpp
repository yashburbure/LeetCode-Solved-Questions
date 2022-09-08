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
vector<int> ans;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode*& root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<TreeNode*> st;
        ans.clear();
        TreeNode* curr=root;
        while(curr || st.size()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            ans.push_back(curr->val);
            st.pop();
            curr=curr->right;
        }
        return ans;
    }
};