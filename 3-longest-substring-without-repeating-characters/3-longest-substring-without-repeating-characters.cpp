class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;  
        int j=-1;
        vector<int> last_pos(256,-1);
        for(int i=0;i<s.length();i++){
            j=max(j,last_pos[s[i]]);
            last_pos[s[i]]=i;
            ans=max(ans,i-j);
        }
        return ans;
    }
};