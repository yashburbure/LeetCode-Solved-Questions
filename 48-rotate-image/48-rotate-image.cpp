class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0;i<n/2;i++){
            for(int j=n-i-1,k=i;j>=i && k<n ;j--,k++){
                ans[i][k]=matrix[j][i];
            }
            for(int j=i,k=i;j<n-i && k<n;j++,k++){
                ans[k][n-1-i]=matrix[i][j];
            }
            for(int j=i,k=n-1-i;j<n-i;j++,k--){
                ans[n-1-i][k]=matrix[j][n-1-i];
            }
            for(int j=n-1-i,k=n-1-i;j>=i;j--,k--){
                ans[k][i]=matrix[n-1-i][j];
            }
        }
        if(n&1){
            ans[n/2][n/2]=matrix[n/2][n/2];
        }
        matrix=ans;
    }
};