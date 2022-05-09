map<int,vector<char>> mp={{2,{'a','b','c'}},{3,{'d','e','f'}},{4,{'g','h','i'}},{5,{'j','k','l'}},{6,           {'m','n','o'}},{7,{'p','q','r','s'}},{8,{'t','u','v'}},{9,{'w','y','x','z'}}};
vector<string> ans;
class Solution {
public:
    void find_ans(int i,int n,string s,string digits){
        if(i==n){
            if(s.length())ans.push_back(s);
            return;
        }
        for(auto it:mp[(digits[i]-'0')]){
            find_ans(i+1,n,s+it,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        ans.clear();
        find_ans(0,digits.length(),"",digits);
        return ans;
    }
};