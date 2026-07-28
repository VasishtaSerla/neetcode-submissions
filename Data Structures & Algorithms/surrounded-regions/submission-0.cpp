class Solution {
public:
    int row,col;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    bool inbounds(int row,int col,int x,int y){return (x>=0 && x<row && y>=0 && y<col);}
   vector<pair<int,int>>ans;

    void dfs(vector<vector<char>>& board,vector<vector<int>>& visited,int x,int y){
      if(visited[x][y])return;
      visited[x][y] = 1;
      ans.push_back({x,y});
      for(int i = 0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(inbounds(row,col,nx,ny) && !visited[nx][ny] && board[nx][ny]=='O')dfs(board,visited,nx,ny);
      }
    }
    void solve(vector<vector<char>>& board) {
    row = board.size();
    col = board[0].size();
     vector<vector<int>>visited(row,vector<int>(col,0));
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if((i==0||i==row-1||j==0||j==col-1) && board[i][j]=='O')dfs(board,visited,i,j);
        }
    }
     for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
      board[i][j] = 'X';
        }
    }
    for(auto x:ans){
        board[x.first][x.second] = 'O';
    }
    return;
    }
};