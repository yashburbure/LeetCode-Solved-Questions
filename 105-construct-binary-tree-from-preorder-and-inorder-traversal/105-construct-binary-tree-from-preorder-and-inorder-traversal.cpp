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
    int find_index(vector<int>& inorder,int val){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* build_Tree(vector<int>& preorder,vector<int>& inorder,int st,int end,int &ind){
        if(st>end ||st<0||st>=inorder.size()||end<0||end>=inorder.size()) return NULL;
        int cur_val=preorder[ind];
        TreeNode* nn=new TreeNode(cur_val);
        ind++;
        if(st==end) return nn;
        int pos=find_index(inorder,cur_val);
        nn->left=build_Tree(preorder,inorder,st,pos-1,ind);
        nn->right=build_Tree(preorder,inorder,pos+1,end,ind);
        return nn;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind=0;
        TreeNode* ans=build_Tree(preorder,inorder,0,inorder.size()-1,ind);
        return ans;
    }
};