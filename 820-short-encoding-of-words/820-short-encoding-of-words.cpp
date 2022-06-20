class Trie{
    public:
        Trie* child[26];
        vector<int> ind;
        Trie(){
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }   
        }
};
void insert(Trie* root,string& s,int i,int ind){
    if(i==s.length()-1){
        root->ind.push_back(ind);
        return;
    }
    if(root->child[s[i+1]-'a']){
        insert(root->child[s[i+1]-'a'],s,i+1,ind);
    }
    else{
        Trie* nn=new Trie();
        root->child[s[i+1]-'a']=nn;
        insert(root->child[s[i+1]-'a'],s,i+1,ind);
    }
}
void traverse(Trie* root,string s,int i,vector<bool>& vis){
    for(auto &it:root->ind){
        vis[it]=1;
    }
    if(i==s.length()-1){
        return;
    }
    traverse(root->child[s[i+1]-'a'],s,i+1,vis);
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* root=new Trie();
        int ans=0;
        int n=words.size();
        sort(words.begin(),words.end(),[&](string& a,string& b){
            return a.length()>b.length();
        });
        for(int i=0;i<n;i++){
            reverse(words[i].begin(),words[i].end());
            
            if(root->child[words[i][0]-'a']){
                insert(root->child[words[i][0]-'a'],words[i],0,i);
            }
            else{
                Trie* nn=new Trie();
                root->child[words[i][0]-'a']=nn;
                insert(root->child[words[i][0]-'a'],words[i],0,i);
            }
        }
        vector<bool> vis(n,0);
        string s;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            ans+=words[i].length()+1;
            traverse(root->child[words[i][0]-'a'],words[i],0,vis);
        }
        return ans;
    }
};