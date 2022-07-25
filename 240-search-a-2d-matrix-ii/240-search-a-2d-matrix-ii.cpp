class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int& target) {
        short int i=0;
        short int j=matrix[0].size()-1;
        while(1){
            if(j<0 || i>=matrix.size()) return false;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
    }
};