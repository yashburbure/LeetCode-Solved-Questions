class Solution {
public:
    bool canConstruct(string &ransomNote, string& magazine) {
        int freq[26]={0};
        for(char &ch:magazine) freq[ch-'a']++;
        for(char &ch:ransomNote){
            if(!freq[ch-'a']) return false;
            freq[ch-'a']--;
        }
        return true;
    }
};