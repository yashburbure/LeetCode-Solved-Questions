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
    map<pair<int,int>,vector<TreeNode*>> mp;
    vector<TreeNode*> generate_Tree(int st,int end){
        vector<TreeNode*> Trees;
        if(mp.find({st,end})!=mp.end()) return mp[{st,end}];
        if(st>end){
            Trees.push_back(NULL);
            return Trees;
        }
        for(int i=st;i<=end;i++){
            vector<TreeNode*> leftTree=generate_Tree(st,i-1);
            vector<TreeNode*> rightTree=generate_Tree(i+1,end);
            for(int j=0;j<leftTree.size();j++){
                for(int k=0;k<rightTree.size();k++){
                    TreeNode* nn=new TreeNode(i);
                    nn->left=leftTree[j];
                    nn->right=rightTree[k];
                    Trees.push_back(nn);
                }
            }
        }
        return mp[{st,end}]=Trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> Trees=generate_Tree(1,n);
        return Trees;
    }
};