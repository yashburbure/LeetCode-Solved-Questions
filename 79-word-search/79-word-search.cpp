class Solution {
public:
    vector<vector<bool>> vis{7,vector<bool>(7)};
    vector<pair<int,int>> moves={{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    bool findString(int i,int j,string& word,int ind,vector<vector<char>>& board){
        if(ind==word.length()){
            return true;
        }
        int v_x,v_y;
        bool ans=false;
        for(auto &mov:moves){
            v_x=mov.first+i;
            v_y=mov.second+j;
            if(!isSafe(v_x,v_y,board.size(),board[0].size())) continue;
            if(vis[v_x][v_y]) continue;
            if(board[v_x][v_y]==word[ind]){
                vis[v_x][v_y]=true;
                ans|=findString(v_x,v_y,word,ind+1,board);
                vis[v_x][v_y]=false;
            }
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    vis[i][j]=true;
                    if(findString(i,j,word,1,board)) return true;
                    vis[i][j]=false;   
                }
            }
        }
        return false;
    }
};