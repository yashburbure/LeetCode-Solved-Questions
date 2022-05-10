class Solution {
public:
    bool is_safe(int m,int n,vector<string>& board){
        int size=board.size();
        for(int i=m-1;i>=0;i--){
            if(board[i][n]=='Q') return 0;
        }
        for(int i=n-1;i>=0;i--){
            if(board[m][i]=='Q') return 0;
        }
        for(int i=m-1,j=n-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return 0;
        }
        for(int i=m-1,j=n+1;i>=0 && j<size;i--,j++){
            if(board[i][j]=='Q') return 0;
        }
        return 1;
    }
    void back_trap(vector<vector<string>> &ans,int n,int row,vector<string>& board){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(is_safe(row,i,board)){
                board[row][i]='Q';
                back_trap(ans,n,row+1,board);
            }
            board[row][i]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        back_trap(ans,n,0,board);
        return ans;
    }
};