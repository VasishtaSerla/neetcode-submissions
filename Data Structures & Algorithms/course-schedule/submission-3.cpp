class Solution {
public:
    bool ans = true;
//detect a cycle in the graph
    void dfs(vector<vector<int>>&adj, int index,vector<int>&visited,vector<int>&path){
        visited[index] = 1;
        path[index] = 1;
    for(auto x:adj[index]){
        if(visited[x]){
            if(path[x]){
                ans = false;
                return;
            }continue;
        }
        dfs(adj,x,visited,path);
    }            path[index] = 0;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adjList(numCourses);
  vector<int>visited(1000,0);
  vector<int>path_set(1000,0);
    for(auto x:prerequisites)adjList[x[0]].push_back(x[1]);
   
for(int i =0; i<numCourses; i++) {
if(!visited[i])dfs(adjList,i,visited,path_set);
if(!ans)return false;
}
        return ans;
    }
};