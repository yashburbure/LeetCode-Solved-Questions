class Trie{
    public:
        Trie* child[26];
        bool wordend;
        Trie(){
            for(int i=0;i<26;i++){
                wordend=false;
                child[i]=NULL;
            }
        }
};
void insert(Trie*& root,string& word,int& ind){
    if(word.length()==ind){
        root->wordend=true;
        return;
    }
    int nind=word[ind]-'a';
    ind++;
    if(root->child[nind]){
        insert(root->child[nind],word,ind);
    }
    else{
        root->child[nind]=new Trie();
        insert(root->child[nind],word,ind);
    }
}
bool Search(Trie* root,string& word,int ind){
    if(ind==word.length()){
        return root->wordend;
    }
    bool ans=false;
    if(word[ind]=='.'){
        for(int i=0;i<26;i++){
            if(root->child[i]){
                ans|=Search(root->child[i],word,ind+1);
            }
        }
        return ans;
    }
    else if(root->child[word[ind]-'a']){
        return Search(root->child[word[ind]-'a'],word,ind+1);
    }
    return false;
}
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root=new Trie();
    }
    void addWord(string word) {
        int ind=0;
        insert(root,word,ind);
    }
    
    bool search(string word) {
        return Search(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */