class Solution {
public:
    int longestPalindrome(string s) {
        int freq[256]={0};
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        cout<<endl;
        int ans=0;
        for(char ch='a';ch<='z';ch++){
            ans+=(freq[ch]/2)*2;
        }
        for(char ch='A';ch<='Z';ch++){
            ans+=(freq[ch]/2)*2;
        }
        if(ans<s.length()) ans++;
        return ans;
    }
};