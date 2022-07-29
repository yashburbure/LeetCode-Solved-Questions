class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string& pattern) {
        vector<string> ans;
        unordered_map<char,char> mp1,mp2;
        bool flag;
        short int i;
        for(string& it:words){
            flag=true;
            for(i=0;i<pattern.length();i++){
                if(mp1.find(pattern[i])!=mp1.end()){
                    if(mp1[pattern[i]]!=it[i]){
                        flag=false;
                    }
                }
                else if(mp2.find(it[i])!=mp2.end()){
                    flag=false;
                }
                else{
                    if(mp2.find(it[i])!=mp2.end()){
                        flag=false;
                    }
                    else{
                        mp1[pattern[i]]=it[i];
                        mp2[it[i]]=pattern[i];   
                    }
                }
            }
            if(flag){
                ans.push_back(it);
            }
            mp1.clear();
            mp2.clear();
        }
        return ans;
    }
};