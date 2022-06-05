class Solution {
public:
    void palindrome_partition(string &s,int st,int end,int n,vector<vector<bool>>& dp,
                              vector<string> curr_part,vector<vector<string>>& ans){
        if(st==n || end==n){
            if(st==n && end==n){
                ans.push_back(curr_part);                
            }
            return;
        }
        if(dp[end][st]){
            vector<string> new_par=curr_part;
            string partition_mem="";
            for(int i=st;i<=end;i++){
                partition_mem.push_back(s[i]);
            }
            curr_part.push_back(partition_mem);
            palindrome_partition(s,end+1,end+1,n,dp,curr_part,ans);
            palindrome_partition(s,st,end+1,n,dp,new_par,ans);
        }
        else{
            palindrome_partition(s,st,end+1,n,dp,curr_part,ans);
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            for(int j=i-1;j>=0;j--){
                int diff=i-j;
                if(diff==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i-1][j+1]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        palindrome_partition(s,0,0,n,dp,{},ans);
        return ans;
    }
};