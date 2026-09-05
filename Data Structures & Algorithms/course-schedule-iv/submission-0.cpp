class Solution {
public:

    bool dfs(int u, int target, vector<vector<int>>& adj,
             vector<bool>& vis)
    {
        if (u == target)
            return true;

        vis[u] = true;

        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                if (dfs(v, target, adj, vis))
                    return true;
            }
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries)
    {
        vector<vector<int>> adj(numCourses);

        for (auto edge : prerequisites)
        {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
        }

        vector<bool> ans;

        for (auto q : queries)
        {
            int u = q[0];
            int v = q[1];

            vector<bool> vis(numCourses, false);

            ans.push_back(dfs(u, v, adj, vis));
        }

        return ans;
    }
};