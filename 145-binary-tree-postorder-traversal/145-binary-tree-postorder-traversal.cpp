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
    vector<int> postorderTraversal(TreeNode*& root) {
        vector<int> ans;
        if(!root) return ans;
        stack<pair<TreeNode*,short int>> st;
        st.push({root,0});
        pair<TreeNode*,short int> temp;
        while(st.size()){
            temp=st.top();
            if(temp.second==0){
                st.pop();
                st.push({temp.first,1});
                if(temp.first->left) st.push({temp.first->left,0});
            }
            else if(temp.second==1){
                st.pop();
                st.push({temp.first,2});
                if(temp.first->right) st.push({temp.first->right,0});
            }
            else{
                st.pop();
                ans.push_back(temp.first->val);
            }
        }
        return ans;
    }
};