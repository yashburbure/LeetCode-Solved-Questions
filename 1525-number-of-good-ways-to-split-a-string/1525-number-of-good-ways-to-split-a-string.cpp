class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mp1,mp2;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp1.size()==mp2.size()) ans++;
            mp1[s[i]]--;
            mp2[s[i]]++;
            if(mp1[s[i]]==0){
                mp1.erase(mp1.find(s[i]));
            }
        }
        return ans;
    }
};