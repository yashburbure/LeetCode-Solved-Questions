class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                int diff=i-j;
                if(diff==1 || diff==0){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                        ans++;
                    }
                    else dp[i][j]=0;
                }
                else{
                    if(s[i]==s[j] && dp[i-1][j+1]==1){
                        dp[i][j]=1;
                        ans++;
                    }
                    else dp[i][j]=0;
                }
            }
        }
        return ans;
    }
};