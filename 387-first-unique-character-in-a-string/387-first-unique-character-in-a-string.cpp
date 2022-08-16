class Solution {
public:
    int firstUniqChar(string& s) {
        int freq[26]={0};
        for(char &ch:s){
            freq[ch-'a']++;
        }
        int i=0;
        for(char &ch:s){
            if(freq[ch-'a']==1) return i;
            i++;
        }
        return -1;
    }
};