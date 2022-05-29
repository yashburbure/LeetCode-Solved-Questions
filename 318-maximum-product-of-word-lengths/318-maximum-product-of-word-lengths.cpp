class Solution {
public:
    int max(int a,int b){
        return (a>b)?a:b;
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<unordered_map<char,bool>> mp;
        for(int j=0;j<n;j++){
            unordered_map<char,bool> curr;
            for(int i=0;i<words[j].length();i++){
                curr[words[j][i]]=1;
            }
            mp.push_back(curr);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool flag=1;
                for(char ch='a';ch<='z';ch++){
                    if(mp[i][ch]==1 && mp[j][ch]==1) flag=0;
                }
                if(flag) ans=max(ans,words[i].length()*words[j].length());
            }
        }
        return ans;
    }
};