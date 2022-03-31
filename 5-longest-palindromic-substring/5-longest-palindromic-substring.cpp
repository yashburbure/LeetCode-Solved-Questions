class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        bool dp[n][n];
        int diff;
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
            for(int j=i-1;j>=0;j--){
                if(s[j]==s[i]){
                    diff=i-j;
                    if(diff==1) dp[j][i]=1;
                    else dp[j][i]=dp[j+1][i-1];
                }
                else{
                    dp[j][i]=0;
                }
            }
        }
        int mxlen=0;
        pair<int,int> st_end={0,0};
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(dp[i][j]){
                    if(j-i+1>mxlen){
                        mxlen=j-i+1;
                        st_end={i,j};
                    }
                }
            }
        }
        string ans="";
        for(int i=st_end.first;i<=st_end.second;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};