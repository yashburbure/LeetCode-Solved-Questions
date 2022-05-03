/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        pair<Node*,int> curr,temp;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            if(curr.first->left) q.push({curr.first->left,curr.second+1});
            if(curr.first->right) q.push({curr.first->right,curr.second+1});
            if(!q.empty()){
                temp=q.front();
                if(temp.second==curr.second){
                    curr.first->next=temp.first;
                }
                else{
                    curr.first->next=NULL;
                }
            }
        }
        return root;
    }
};