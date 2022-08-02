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
    void inorder(TreeNode*& root,vector<int>& InorderArray){
        if(!root) return;
        inorder(root->left,InorderArray);
        InorderArray.push_back(root->val);
        inorder(root->right,InorderArray);
    }
    TreeNode* buildBST(int st,int end,vector<int>& InorderArray){
        if(st>end){
            return NULL;
        }
        int mid=(st+end)/2;
        TreeNode* nn=new TreeNode(InorderArray[mid]);
        nn->left=buildBST(st,mid-1,InorderArray);
        nn->right=buildBST(mid+1,end,InorderArray);
        return nn;
    }
    TreeNode* balanceBST(TreeNode*& root) {
        vector<int> InorderArray;
        inorder(root,InorderArray);
        return buildBST(0,InorderArray.size()-1,InorderArray);
    }
};