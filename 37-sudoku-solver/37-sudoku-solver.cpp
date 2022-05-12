class Solution {
public:
    vector<vector<char>> ans={};
    map<tuple<int,int,char>,bool> mp;
    bool is_safe(int row,int col,vector<vector<char>>& board,char ch){
        for(int i=0;i<9;i++){
            if(i==col) continue;
            if(board[row][i]==ch) return 0;
        }
        for(int i=0;i<9;i++){
            if(i==row) continue;
            if(board[i][col]==ch) return 0;
        }
        return 1;
    }
    void solve_sudoku(int i,int j,vector<vector<char>>& board){
        if(ans.size()) return;
        if(i==8 && j==9){
            ans=board;
            return;
        }
        else if(j==9){
            solve_sudoku(i+1,0,board);
            return;
        }
        if(board[i][j]=='.'){
            for(char ch='1';ch<='9';ch++){
                if(is_safe(i,j,board,ch) && mp[{i/3,j/3,ch}]==0){
                    mp[{i/3,j/3,ch}]=1;
                    board[i][j]=ch;
                    solve_sudoku(i,j+1,board);
                    board[i][j]='.';
                    mp[{i/3,j/3,ch}]=0;
                }
            }
        }
        else{
            mp[{i/3,j/3,board[i][j]}]=1;
            solve_sudoku(i,j+1,board);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve_sudoku(0,0,board);
        board=ans;
    }
};