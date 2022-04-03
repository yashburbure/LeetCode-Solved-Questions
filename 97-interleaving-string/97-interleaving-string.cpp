class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        if(l3!=l1+l2) return 0;
        bool dp[l3+1][l1+1][l2+1];
        for(int i=0;i<=l3;i++){
            for(int j=0;j<=l1;j++){
                for(int k=0;k<=l2;k++) dp[i][j][k]=0;
            }
        }
        for(int i=0;i<=l3;i++){
            for(int j=0;j<=i&&j<=l1;j++){
                for(int k=0;k+j<=i&&k<=l2;k++){
                    if(i==0&&j==0&&k==0){
                        dp[0][0][0]=1;
                    }
                    else if(j==0&&k==0){
                        dp[i][j][k]=0;
                    }
                    else if(j==0){
                        if(s3[i-1]==s2[k-1]){
                            dp[i][j][k]=dp[i-1][j][k-1];
                        }
                        else dp[i][j][k]=0;
                    }
                    else if(k==0){
                        if(s3[i-1]==s1[j-1]){
                            dp[i][j][k]=dp[i-1][j-1][k];
                        }
                        else dp[i][j][k]=0;
                    }
                    else{
                        if(s3[i-1]==s1[j-1]&&s3[i-1]==s2[k-1]){
                            dp[i][j][k]=dp[i-1][j-1][k]|dp[i-1][j][k-1];
                        }
                        else if(s3[i-1]==s1[j-1]){
                            dp[i][j][k]=dp[i-1][j-1][k];
                        }
                        else if(s3[i-1]==s2[k-1]){
                            dp[i][j][k]=dp[i-1][j][k-1];
                        }
                        else dp[i][j][k]=0;
                    }
                }
            }
        }
        return dp[l3][l1][l2];
    }
};