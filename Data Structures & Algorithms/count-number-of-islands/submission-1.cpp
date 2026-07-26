class Solution {
public:
    int count = 0,row,col;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool check(int m, int n, int x, int y){
        return(x>=0&&y>=0&&x<m&&y<n);
    }
    //call dfs from vertex (x,y);
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int x,int y){
    if(grid[x][y]=='0')return;    
    visited[x][y] = 1;
    for(int i = 0; i<4; i++){
        if(check(row,col,x+dx[i],y+dy[i]) && !visited[x+dx[i]][y+dy[i]]){
        dfs(grid,visited,x+dx[i],y+dy[i]);
        }  //in all 4directions recursive call
    }
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                  dfs(grid,visited,i,j); 
                  count++;   
                } 
            }
        }

        return count;
    }
};
