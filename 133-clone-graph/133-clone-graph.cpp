/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*>& mp){
        Node* nn=new Node(node->val);
        mp[node]=nn;
        for(auto &it:node->neighbors){
            if(mp.find(it)==mp.end())
                nn->neighbors.push_back(dfs(it,mp));
            else nn->neighbors.push_back(mp[it]);
        }
        return nn;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*,Node*> mp;
        Node* ans=dfs(node,mp);
        return ans;
    }
};