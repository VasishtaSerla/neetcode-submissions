class Solution {
public:
    queue<pair<int,int>>q; 
    int row,col,fresh_oranges = 0,minute = 1,rotten_oranges = 0;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    bool inbounds(int row,int col,int x, int y) {return(x>=0 && x<row && y>=0 && y<col);}

    void bfs(vector<vector<int>>&grid){
        
      while(!q.empty()){
        int size = q.size();
        
        for(int i = 0; i<size; i++){
         pair<int,int>curr = q.front();
        q.pop();
             for(int i = 0; i<4; i++){
             int nx = curr.first + dx[i];
             int ny = curr.second + dy[i];
             if(inbounds(row,col,nx,ny) && grid[nx][ny]!=0){
                if(grid[nx][ny]==1){
                    grid[nx][ny] = 2;
                    fresh_oranges--;
                    if(fresh_oranges==0)return;
                    q.push({nx,ny});
                }
              }
           }
        }
        minute++;
      }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j]==1)fresh_oranges++;
                else if(grid[i][j]==2){
                    rotten_oranges++;
                     q.push({i,j});
                    }
              }
        }if(fresh_oranges==0)return 0;
         else{
            if(rotten_oranges==0)return -1;
         }
        bfs(grid);
        if(fresh_oranges>0)return -1;
        else return minute;
    }
};