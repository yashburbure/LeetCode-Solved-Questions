class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        int previous[n+1];
        previous[0]=0;
        for(int i=1;i<=n;i++){
            previous[i]=1e9;
        }
        for(int i=1;i<=100;i++){
            for(int j=0;j<=n;j++){
                if(j==0){
                    dp[j]=0;
                }
                else{
                    dp[j]=previous[j];
                    if(j-i*i>=0){
                        if(dp[j]>1+dp[j-i*i]){
                            dp[j]=1+dp[j-i*i];
                        }
                    }
                }
            }
            for(int j=0;j<=n;j++){
                previous[j]=dp[j];
            }
        }
        return dp[n];
    }
};