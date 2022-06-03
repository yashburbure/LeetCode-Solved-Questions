class NumMatrix {
public:
    vector<vector<int>> A;
    int prefix[205][205];
    NumMatrix(vector<vector<int>>& matrix) {
        A=matrix;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    prefix[i][j]=0;
                }
                else{
                    prefix[i][j]=matrix[i-1][j-1]+
                        prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=prefix[row2+1][col2+1];
        ans-=prefix[row2+1][col1];
        ans-=prefix[row1][col2+1];
        ans+=prefix[row1][col1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */