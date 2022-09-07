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
int goodNodesRec(TreeNode*& root,int mxValue){
    if(!root) return 0;
    int ans;
    if(root->val>=mxValue){
        ans=1;
        ans+=goodNodesRec(root->left,root->val)+goodNodesRec(root->right,root->val);
    }
    else{
        ans=0;
        ans+=goodNodesRec(root->left,mxValue)+goodNodesRec(root->right,mxValue);
    }
    return ans;
}
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return goodNodesRec(root,INT_MIN);
    }
};