class Solution {
public:
    bool in_grid(int x,int y,int m,int n){
        if(x>=0&&x<=m-1&&y>=0&&y<=n-1)return true;
        else return false;
    }
    int paths(int x,int y,int m,int n,vector<vector<int>>&mem){//number of paths from xy to mn
       if(x==m-1 && y==n-1)return 1;
       if(!in_grid(x,y,m,n))return 0;
       if(mem[x][y]!=-1)return mem[x][y];
       return mem[x][y] = paths(x+1,y,m,n,mem)+paths(x,y+1,m,n,mem);
              
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>mem(m,vector<int>(n,-1));
        return paths(0,0,m,n,mem);
    }
};
