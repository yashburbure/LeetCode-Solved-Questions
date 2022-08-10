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
    TreeNode* build_tree(vector<int>& nums,int &st,int &end){
        if(st>end) return NULL;
        int mid=(st+end)/2;
        TreeNode* nn=new TreeNode(nums[mid]);
        mid--;
        nn->left=build_tree(nums,st,mid);
        mid+=2;
        nn->right=build_tree(nums,mid,end);
        return nn;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int st=0,end=nums.size()-1;
        return build_tree(nums,st,end);
    }
};