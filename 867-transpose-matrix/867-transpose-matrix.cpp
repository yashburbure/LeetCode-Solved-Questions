class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> ans;
        for(int j=0;j<n;j++){
            vector<int> curr_row;
            for(int i=0;i<m;i++){
                curr_row.push_back(matrix[i][j]);
            }
            ans.push_back(curr_row);
        }
        return ans;
    }
};