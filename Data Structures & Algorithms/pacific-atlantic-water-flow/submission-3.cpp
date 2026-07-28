class Solution {
public:
    int row,col;
     int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>>ans;
    bool inbounds(int row,int col,int x,int y){return (x>=0 && x<row && y>=0 && y<col);}

    void dfs(vector<vector<int>>& heights,vector<vector<int>>&visited,int x,int y){
    if(visited[x][y])return;
        visited[x][y] = 1;
      for(int i = 0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(inbounds(row,col,nx,ny) && !visited[nx][ny] && heights[nx][ny]>=heights[x][y])dfs(heights,visited,nx,ny);
      }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       row = heights.size();
       col = heights[0].size();
       vector<vector<int>>pacific_flag(row,vector<int>(col,0));
       vector<vector<int>>atlantic_flag(row,vector<int>(col,0));
        //i=0 || j = 0            i=size-1 ||j = size-1 
                 // pacific               atlantic
        for(int i = 0; i<row; i++)dfs(heights,pacific_flag,i,0);
    
        for(int j = 0; j<col; j++)dfs(heights,pacific_flag,0,j);
        
        for(int i = 0; i<row; i++)dfs(heights,atlantic_flag,i,col-1);
        
        for(int j = 0; j<col; j++)dfs(heights,atlantic_flag,row-1,j);
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(pacific_flag[i][j] && atlantic_flag[i][j])ans.push_back({i,j});
            }
        }
                       return ans;
        }
};