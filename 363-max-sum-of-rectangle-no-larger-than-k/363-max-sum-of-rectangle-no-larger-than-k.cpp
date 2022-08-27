class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int prefix[n+1][m+1];
        int ans=INT_MIN;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    prefix[i][j]=0;
                }
                else{
                    if(matrix[i-1][j-1]<=k) ans=max(ans,matrix[i-1][j-1]);
                    prefix[i][j]=matrix[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
                }
            }
        }
        // cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int ki=n;ki>i;ki--){
                    for(int l=m;l>j;l--){
                        int sum=prefix[ki][l]-prefix[ki][l-j-1]-
                            prefix[ki-1-i][l]+prefix[ki-1-i][l-1-j];
                        if(sum<=k){
                            // cout<<ki<<" "<<l<<" "<<i<<" "<<j<<" "<<sum<<endl;
                            ans=max(ans,sum);
                        }
                    }
                }
            }
        }
        return ans;
    }
};