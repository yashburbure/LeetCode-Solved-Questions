class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<pair<char,int>> st;
        int ans=0;
        vector<int> dp(n,0);
        pair<char,int> tp;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push({s[i],i});
                dp[i]=0;
            }
            else{
                if(!st.empty() && st.top().first=='('){
                    tp=st.top();
                    st.pop();
                    dp[i]=2;
                    if(tp.second==i-1){
                        if(tp.second==0){
                            dp[i]=2;
                        }
                        else{
                            dp[i]=2+dp[tp.second-1];
                        }
                    }
                    else{
                        if(dp[i-1]==i-tp.second-1){
                            if(tp.second==0){
                                dp[i]=dp[i-1]+2;
                            }
                            else 
                                dp[i]=dp[i-1]+2+dp[tp.second-1];
                        }
                    }
                }
                else{
                    st.push({s[i],i});
                }
            }
            ans=max(dp[i],ans);
        }
        return ans;
    }
};