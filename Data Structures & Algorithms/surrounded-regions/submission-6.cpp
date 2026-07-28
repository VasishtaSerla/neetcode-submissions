class Solution {
public:
    int row,col;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    bool inbounds(int row,int col,int x,int y){return (x>=0 && x<row && y>=0 && y<col);}

    void dfs(vector<vector<char>>& board,vector<vector<int>>& visited,int x,int y,vector<vector<int>>&check){
      if(visited[x][y])return;
      visited[x][y] = 1;
      check[x][y]  = 1;
      for(int i = 0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(inbounds(row,col,nx,ny) && !visited[nx][ny] && board[nx][ny]=='O')dfs(board,visited,nx,ny,check);
      }
    }
    void solve(vector<vector<char>>& board) {
    row = board.size();
    col = board[0].size();
     vector<vector<int>>visited(row,vector<int>(col,0));
     vector<vector<int>>check(row,vector<int>(col,0));
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if((i==0||i==row-1||j==0||j==col-1) && board[i][j]=='O')dfs(board,visited,i,j,check);
        }
    }
     for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(!check[i][j])board[i][j] = 'X';
        }
    }

    return;
    }
};