class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                q.push(matrix[i][j]);
            }
        }
        int ptr=1;
        while(q.size()){
            if(ptr==k){
                return q.top();
            }
            q.pop();
            ptr++;
        }
        return -1;
    }
};