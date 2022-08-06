const int MAXBITS=(1ll<<11);
int dp[41][MAXBITS];
class Solution {
public:
    const int M=1e9+7;
    vector<int> person[41];
    long int ways(int hatIndex,int bitmask,int n){
        if(hatIndex==41){
            if(__builtin_popcount(bitmask)==n){
                return 1;
            }
            return 0;
        }
        if(dp[hatIndex][bitmask]!=-1){
            return dp[hatIndex][bitmask];
        }
        long int arrangements=ways(hatIndex+1,bitmask,n);
        for(int i=0;i<person[hatIndex].size();i++){
            if((bitmask&(1ll<<person[hatIndex][i]))==0){
                arrangements=(arrangements+ways(hatIndex+1,bitmask^(1ll<<person[hatIndex][i]),n))%M;
            }
        }
        return dp[hatIndex][bitmask]=arrangements;
    }
    int numberWays(vector<vector<int>>& hats) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<hats.size();i++){
            for(int j=0;j<hats[i].size();j++){
                person[hats[i][j]].push_back(i);
            }
        }
        return ways(1,0,hats.size());
    }
};