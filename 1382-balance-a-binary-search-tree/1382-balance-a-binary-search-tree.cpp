class Solution {
public:
    void inorder(TreeNode*& root,vector<int>& InorderArray){
        if(!root) return;
        inorder(root->left,InorderArray);
        InorderArray.push_back(root->val);
        inorder(root->right,InorderArray);
    }
    TreeNode* buildBST(int &st,int &end,vector<int>& InorderArray){
        if(st>end){
            return NULL;
        }
        int mid=(st+end)/2;
        TreeNode* nn=new TreeNode(InorderArray[mid]);
        mid--;
        nn->left=buildBST(st,mid,InorderArray);
        mid+=2;
        nn->right=buildBST(mid,end,InorderArray);
        return nn;
    }
    TreeNode* balanceBST(TreeNode*& root) {
        vector<int> InorderArray;
        inorder(root,InorderArray);
        int st=0,end=InorderArray.size()-1;
        return buildBST(st,end,InorderArray);
    }
};