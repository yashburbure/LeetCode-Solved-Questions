class Solution {
public:
    // int minOperation(string &word1,string& word2,int i,int j){
    //     if(j==-1){
    //         return i+1;
    //     }
    //     if(i==-1){
    //         return j+1;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i]==word2[j]){
    //         return minOperation(word1,word2,i-1,j-1);
    //     }
    //     int ans=1+minOperation(word1,word2,i-1,j-1);
    //     ans=min(ans,1+minOperation(word1,word2,i-1,j));
    //     ans=min(ans,1+minOperation(word1,word2,i,j-1));
    //     return dp[i][j]=ans;
    // }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else{
                    if(word1[i-1]==word2[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                    }
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n][m];
    }
};