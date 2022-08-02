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
    void Inorder(TreeNode*& root,vector<pair<int,TreeNode*>>& InorderArray){
        if(!root) return;
        Inorder(root->left,InorderArray);
        InorderArray.push_back({root->val,root});
        Inorder(root->right,InorderArray);
    }
    TreeNode* BuildBST(int lo,int hi,vector<pair<int,TreeNode*>>& InorderArray){
        if(lo>hi) return NULL;
        int mid=(lo+hi)/2;
        TreeNode* nn=InorderArray[mid].second;
        nn->val=InorderArray[mid].first;
        nn->left=BuildBST(lo,mid-1,InorderArray);
        nn->right=BuildBST(mid+1,hi,InorderArray);
        return nn;
    }
    TreeNode* balanceBST(TreeNode*& root) {
        vector<pair<int,TreeNode*>> InorderArray;
        Inorder(root,InorderArray);
        return BuildBST(0,InorderArray.size()-1,InorderArray);
    }
};