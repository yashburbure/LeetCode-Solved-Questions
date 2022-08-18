class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int j=0;
        vector<int> freqS(26,0),freqP(26,0);
        for(int i=0;i<p.length();i++){
            freqP[p[i]-'a']++;
        }
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            freqS[s[i]-'a']++;
            while(freqS[s[i]-'a']>freqP[s[i]-'a']){
                freqS[s[j]-'a']--;
                j++;
            }
            if(freqS==freqP) ans.push_back(j);
        }
        return ans;
    }
};