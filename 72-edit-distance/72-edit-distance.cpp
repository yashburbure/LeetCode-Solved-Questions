class Solution {
public:
    int dp[505][505];
    int minOperation(string &word1,string& word2,int i,int j){
        if(j==-1){
            return i+1;
        }
        if(i==-1){
            return j+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return minOperation(word1,word2,i-1,j-1);
        }
        int ans=1+minOperation(word1,word2,i-1,j-1);
        ans=min(ans,1+minOperation(word1,word2,i-1,j));
        ans=min(ans,1+minOperation(word1,word2,i,j-1));
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int ans=minOperation(word1,word2,word1.length()-1,word2.length()-1);
        return ans;
    }
};