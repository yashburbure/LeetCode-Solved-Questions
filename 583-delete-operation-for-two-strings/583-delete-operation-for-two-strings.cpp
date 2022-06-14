int dp[505][505];
class Solution {
public:
    int minDistancedp(string &word1,string &word2,int i,int j){
        if(i<0 || j<0){
            if(i<0 && j<0) return 0;
            if(i<0) return j+1;
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=minDistancedp(word1,word2,i-1,j-1);
        }
        int ans=1+minDistancedp(word1,word2,i,j-1);
        ans=min(ans,1+minDistancedp(word1,word2,i-1,j));
        return dp[i][j]=ans;
    }
    int minDistance(string &word1, string &word2) {
        memset(dp,-1,sizeof(dp));
        return minDistancedp(word1,word2,word1.size()-1,word2.size()-1);
    }
};