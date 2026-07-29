class Solution {
public:

queue<int>q;
vector<int>ans;
 
    void kahn(vector<vector<int>>&adj,vector<int>&indegree){
        while(!q.empty()){
          int size = q.size();
          for(int i = 0; i<size; i++){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto x:adj[curr]){
                indegree[x]--;
                if(!indegree[x])q.push(x);
             }
          }
       }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adjList(numCourses);
    vector<int>indegree(numCourses,0);

    for(auto x:prerequisites){
        adjList[x[1]].push_back(x[0]);
        indegree[x[0]]++;
    }
  
   for(int i = 0; i<numCourses; i++)if(!indegree[i])q.push(i);
kahn(adjList,indegree);

if(ans.size()!=numCourses)return {};
   return ans;
    }
};
