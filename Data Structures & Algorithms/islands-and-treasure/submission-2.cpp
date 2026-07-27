class Solution {
public:

    int level = 0,row,col,found = 0;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    bool inbounds(int row,int col,int x, int y){
        return (x>=0 && x<row && y>=0 && y<col);
    }

    void bfs(vector<vector<int>>& grid,vector<vector<int>>&visited,int &level,int x,int y){
    //normal bfs
    visited[x][y] = 1;
    queue<pair<int,int>>q;//push 1 instead of INT_MAX in the queue
    q.push({x,y});
    while(!q.empty()){
       int size = q.size();
        //push all neighbors at once
       for(int i = 0; i<size; i++){
         int curr_x = q.front().first;
         int curr_y = q.front().second;
        q.pop();
            for(int i = 0; i<4; i++){
                int nx = curr_x+dx[i], ny = curr_y + dy[i];
                 if(inbounds(row,col,nx,ny) && grid[nx][ny] != -1 && !visited[nx][ny] ){
                 if(grid[nx][ny]==0){
                    level++;
                    found = 1;
                    return;
                  }
                 q.push({nx,ny});
                 visited[nx][ny] = 1;
                }
            }
        }level++;
    }


    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
         row = grid.size();
         col = grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        vector<vector<int>>store(row,vector<int>(col,0));
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                store[i][j] = grid[i][j];
                visited = vector<vector<int>>(row,vector<int>(col,0));
                if(grid[i][j]==INT_MAX){
                    level = 0,found = 0;
                    bfs(grid,visited,level,i,j);
                   if(found==1)store[i][j] = level;
                }
            }
        }swap(store,grid);
    }
};
