class Solution {
public:
    void find_ans(string curr,int n,int m,vector<string> &ans){
        if(n<=0 && m<=0){
            ans.push_back(curr);
            return;
        }
        if(n==0){
            find_ans(curr+')',n,m-1,ans);
        }
        else{
            if(n==m) find_ans(curr+'(',n-1,m,ans);
            else{
                find_ans(curr+'(',n-1,m,ans);
                find_ans(curr+')',n,m-1,ans);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        find_ans("",n,n,ans);
        return ans;
    }
};