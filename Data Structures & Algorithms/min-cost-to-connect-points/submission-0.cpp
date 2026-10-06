class Solution {
public:
    int weight(int xi, int yi, int xf, int yf)
    {
        return abs(xi - xf) + abs(yi - yf);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> adj(points.size());

        for (int i = 0; i < points.size(); i++)
        {   
            for (int j = i + 1; j < points.size(); j++)
            {
                int w = weight(
                    points[i][0], points[i][1],
                    points[j][0], points[j][1]
                );

                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }

        int ans = 0;
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        vector<bool> used(n, false);
        for(int i=0;i<n;i++)
        {
            int u = -1;

            for (int j = 0; j < n; j++)
            {
                if (!used[j] && (u == -1 || dist[j] < dist[u]))
                {   
                    u = j;
                }
            }
            used[u] = true;
            ans += dist[u];

            for(auto[v,w]:adj[u])
            {
                if(!used[v] && w<dist[v])
                {
                    dist[v] = w;
                }
            }
        }
        return ans;
    }
};
