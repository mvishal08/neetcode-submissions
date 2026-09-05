class Solution {
public:
    bool dfs(int u,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&parent)
    {
        vis[u] = true;
        for(auto v : adj[u])
        {
            if(!vis[v])
            {
                parent[v] = u;
                if (!dfs(v, adj, vis, parent))
                    return false;
            }

            else
            {
                if (parent[u] != v)
                    return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        vector<int>parent(n,-1);
        for(auto edge : edges)
        {
            int a =edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (!dfs(0, adj, vis, parent))
            return false;


        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                return false;
        }

        return true;
    }
};
