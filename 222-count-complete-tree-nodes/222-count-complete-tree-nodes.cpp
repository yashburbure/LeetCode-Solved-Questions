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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(st.size() || curr){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            ans++;
            st.pop();
            curr=curr->right;
        }
        return ans;
    }
};