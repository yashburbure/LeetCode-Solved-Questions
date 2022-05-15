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
    int find_depth(TreeNode* root){
        if(!root) return 0;
        return max(1+find_depth(root->left),1+find_depth(root->right));
    }
    int dfs(TreeNode* root,int level,int depth){
        if(!root) return 0;
        if(level==depth) return root->val;
        return dfs(root->left,level+1,depth)+dfs(root->right,level+1,depth);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth=find_depth(root);
        return dfs(root,1,depth);
    }
};