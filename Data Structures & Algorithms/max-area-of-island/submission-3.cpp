class Solution {
public:
    int curr_area = 0,row,col;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool check(int m, int n, int x, int y){
        return(x>=0&&y>=0&&x<m&&y<n);
    }
    //call dfs from vertex (x,y);
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int x,int y){
    if(grid[x][y]==0)return;    
    visited[x][y] = 1;
    curr_area++;
    for(int i = 0; i<4; i++){
        if(check(row,col,x+dx[i],y+dy[i]) && !visited[x+dx[i]][y+dy[i]]){
        dfs(grid,visited,x+dx[i],y+dy[i]);
        }  //in all 4directions recursive call
    }
    }
    int maxAreaOfIsland(vector<vector<int>>&grid) {
        row = grid.size();
        col = grid[0].size();
vector<int>max_area;
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    curr_area = 0;
                  dfs(grid,visited,i,j);
                  max_area.push_back(curr_area);   
                } 
            }
        }
        if(!max_area.empty()){
        return *(max_element(max_area.begin(),max_area.end()));
    }
    else return 0;}
};
