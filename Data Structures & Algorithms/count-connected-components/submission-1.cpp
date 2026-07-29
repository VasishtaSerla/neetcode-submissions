class Solution
{
public:
    int count = 0;
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int index)
    {
        visited[index] = 1;
        for (auto x : adj[index])
        {
            if (visited[x])
                continue;

            dfs(adj, visited, x);
        }
    }
    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);
        for (auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }
};