/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> ans;
        vector<int> curr;
        queue<Node*> q;
        q.push(root);
        ans.push_back({root->val});
        Node* tp;
        int i,j,n;
        while(q.size()){
            n=q.size();
            for(i=0;i<n;i++){
                tp=q.front();
                q.pop();
                for(j=0;j<tp->children.size();j++){
                    q.push(tp->children[j]);
                    curr.push_back(tp->children[j]->val);
                }
            }
            if(curr.size())
                ans.push_back(curr);
            curr.clear();
        }
        return ans;
    }
};