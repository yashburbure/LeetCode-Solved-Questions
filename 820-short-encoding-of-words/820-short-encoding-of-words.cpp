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
void insert(Trie*& root,string& s,int& i,int& ind){
    if(i==s.length()-1){
        root->ind.push_back(ind);
        return;
    }
    i++;
    if(root->child[s[i]-'a']){
        insert(root->child[s[i]-'a'],s,i,ind);
    }
    else{
        Trie* nn=new Trie();
        root->child[s[i]-'a']=nn;
        insert(root->child[s[i]-'a'],s,i,ind);
    }
}
void traverse(Trie*& root,string& s,int& i,vector<bool>& vis){
    for(auto &it:root->ind){
        vis[it]=1;
    }
    if(i==s.length()-1){
        return;
    }
    i++;
    traverse(root->child[s[i]-'a'],s,i,vis);
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
        int temp;
        for(int i=0;i<n;i++){
            reverse(words[i].begin(),words[i].end());
            temp=0;
            if(root->child[words[i][0]-'a']){
                insert(root->child[words[i][0]-'a'],words[i],temp,i);
            }
            else{
                Trie* nn=new Trie();
                root->child[words[i][0]-'a']=nn;
                insert(root->child[words[i][0]-'a'],words[i],temp,i);
            }
        }
        vector<bool> vis(n,0);
        string s;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            ans+=words[i].length()+1;
            temp=0;
            traverse(root->child[words[i][0]-'a'],words[i],temp,vis);
        }
        return ans;
    }
};