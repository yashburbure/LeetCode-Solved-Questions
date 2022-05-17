/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==target) return cloned;
        TreeNode* ans1=NULL;
        if(original->left) ans1=getTargetCopy(original->left,cloned->left,target);
        TreeNode* ans2=NULL;
        if(original->right) ans2=getTargetCopy(original->right,cloned->right,target);
        if(ans1) return ans1;
        return ans2;
    }
};