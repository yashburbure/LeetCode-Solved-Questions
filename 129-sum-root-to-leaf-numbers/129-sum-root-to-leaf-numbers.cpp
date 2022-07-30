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
    void dfs(TreeNode*& root,string& path,int& PathSum){
        path.push_back('0'+root->val);
        if(root->left && root->right){
            dfs(root->left,path,PathSum);
            dfs(root->right,path,PathSum);
        }
        else if(root->left){
            dfs(root->left,path,PathSum);
        }
        else if(root->right){
            dfs(root->right,path,PathSum);
        }
        else{
            PathSum+=stoi(path);
        }
        path.pop_back();
    }
    int sumNumbers(TreeNode*& root) {
        string path="";
        int PathSum=0;
        dfs(root,path,PathSum);
        return PathSum;
    }
};