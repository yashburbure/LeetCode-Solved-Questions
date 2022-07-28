class Solution {
public:
    bool isAnagram(string& s, string& t) {
        int i;
        vector<int> freq_s(26,0),freq_t(26,0);
        for(i=0;i<s.length();i++){
            freq_s[s[i]-'a']++;
        }
        for(i=0;i<t.length();i++){
            freq_t[t[i]-'a']++;
        }
        for(i=0;i<26;i++){
            if(freq_s[i]!=freq_t[i]) return false;
        }
        return true;
    }
};