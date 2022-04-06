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
    int partition(vector<int>& preorder,int st,int end,int key){
        int ans=st;
        for(int i=st+1;i<=end;i++){
            if(preorder[i]>key) return ans;
            ans=i;
        }
        return ans;
    }
    TreeNode* build_tree(vector<int>& preorder,int &idx,int st,int end){
        if(st>end) return NULL;
        TreeNode* nn=new TreeNode(preorder[idx]);
        int key=preorder[idx];
        idx++;
        if(st==end) return nn;
        int par=partition(preorder,st,end,key);
        nn->left=build_tree(preorder,idx,st+1,par);
        nn->right=build_tree(preorder,idx,par+1,end);
        return nn;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return build_tree(preorder,idx,0,preorder.size()-1);
    }
};