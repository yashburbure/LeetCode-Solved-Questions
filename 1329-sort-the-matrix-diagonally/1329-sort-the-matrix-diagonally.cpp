class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> sortedArray;
        int j,k;
        for(int i=0;i<m;i++){
            j=0;
            k=i;
            while(j<n && k<m){
                sortedArray.push_back(mat[j][k]);
                j++;k++;
            }
            sort(sortedArray.begin(),sortedArray.end());
            j=0;
            k=i;
            while(j<n && k<m){
                mat[j][k]=sortedArray[j];
                j++;k++;
            }
            // for(auto &it:sortedArray){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            sortedArray.clear();
        }
        for(int i=1;i<n;i++){
            j=i;
            k=0;
            while(j<n && k<m){
                sortedArray.push_back(mat[j][k]);
                j++;k++;
            }
            sort(sortedArray.begin(),sortedArray.end());
            j=i;
            k=0;
            while(j<n && k<m){
                mat[j][k]=sortedArray[k];
                j++;k++;
            }
            // for(auto &it:sortedArray){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            sortedArray.clear();
        }
        return mat;
    }
};