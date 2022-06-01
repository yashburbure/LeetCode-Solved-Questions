class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,bool> mp;
        for(int i=0;i<9;i++){
            mp.clear();
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(mp[board[i][j]]){
                    return 0;
                }
                mp[board[i][j]]=1;
            }
        }
        for(int j=0;j<9;j++){
            mp.clear();
            for(int i=0;i<9;i++){
                if(board[i][j]=='.') continue;
                if(mp[board[i][j]]){
                    return 0;
                }
                mp[board[i][j]]=1;
            }
        }
        map<pair<pair<int,int>,char>,bool> freq;
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]=='.') continue;
                        if(freq[{{i/3,j/3},board[k][l]}]) return 0;
                        freq[{{i/3,j/3},board[k][l]}]=1;
                    }
                }
            }
        }
        return 1;
    }
};