class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> cur_row;
        cur_row.push_back(1);
        ans.push_back(cur_row);
        for(int i=2;i<=numRows;i++){
            int lim=i-2;
            cur_row.clear();
            cur_row.push_back(1);
            int it=1;
            while(lim--){
                cur_row.push_back(ans[i-2][it]+ans[i-2][it-1]);
                it++;
            }
            cur_row.push_back(1);
            ans.push_back(cur_row);
        }
        return ans;
    }
};