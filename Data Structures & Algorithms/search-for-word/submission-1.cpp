class Solution {
public:
bool ans = false;
int dx[4] = {-1,0,1,0};
int dy[4] = {0, 1, 0, -1};

void f(vector<vector<char>>& board, string word,int index,int x,int y,vector<vector<int>>visited){
//out of bounds case return "ASAP"
 if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
 if(visited[x][y])return;
if(word[index]!=board[x][y])return;
else {
  index++;
visited[x][y]=1;
}
if(index==word.size()){
  ans = true;
  return;
}
 for(int i = 0; i<4; i++){
  f(board,word,index,x+dx[i],y+dy[i],visited);
 }
}
    bool exist(vector<vector<char>>& board, string word) {
     int rows = board.size();
     int columns = board[0].size();
        for(int i = 0; i<board.size(); i++){
          for(int j = 0; j<board[0].size(); j++){
            vector<vector<int>>visited(rows,vector<int>(columns,0));
            //they become 1 when visited.
            f(board,word,0,i,j,visited);
            if(ans)return true;
          }
        }return false;
    }
};
