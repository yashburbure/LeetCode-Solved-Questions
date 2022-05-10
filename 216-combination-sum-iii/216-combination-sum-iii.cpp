class Solution {
public:
    void find_ans(vector<vector<int>>& ans,int sum,int no_used,vector<int> &curr,int last_ele,int &k){
        if(sum==0 && no_used==k){
            ans.push_back(curr);
            return ;
        }
        for(int i=last_ele+1;i<=9;i++){
            if(sum-i>=0){
                vector<int> temp=curr;
                temp.push_back(i);
                find_ans(ans,sum-i,no_used+1,temp,i,k);
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        find_ans(ans,n,0,curr,0,k);
        return ans;
    }
};