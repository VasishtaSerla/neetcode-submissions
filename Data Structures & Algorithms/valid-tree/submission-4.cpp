class Solution
{
public:
    bool ans = true;
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int index, int parent)
    {
        if (visited[index])
            return;
        visited[index] = 1;
        for (auto x : adj[index])
        {
            if (visited[x])
            {
                if (x != parent){
                    ans = false;
                return;}
                else {
                    continue;
                }
            }
            dfs(adj, visited, x, index);
        }
    }
    bool validTree(int n, vector<vector<int>> &edges)
    {
        if (edges.size() != n - 1)
            return false;
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        for (auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        dfs(adj, visited, 0, -1);
        if (!ans)
            return false;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                return false;
        }
        return true;
    }
};