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
class TreeVNode{
    public:
    TreeNode* root;
    int vis;
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeVNode> st;
        vector<int> ans;
        if(root){
            st.push({root,0});
            while(st.size()){
                TreeVNode top=st.top();
                st.pop();
                if(top.vis){
                    ans.push_back(top.root->val);
                }
                else{
                    top.vis=1;
                    if(top.root->right){
                        st.push({top.root->right,0});
                    }
                    st.push(top);
                    if(top.root->left){
                        st.push({top.root->left,0});
                    }
                }
            }
            return ans;
        }
        else return ans;
    }
};