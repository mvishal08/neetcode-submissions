class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        int m = times.size();
        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }
        vector<long long> dist(n + 1, 1e8);
        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;
 
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if(d !=  dist[u]) continue;

            for(auto[v, w] : adj[u])
            {
                if(dist[v] > d + w)
                {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e8)
                return -1;

            ans = max(ans, (int)dist[i]);
        }

        return ans;

    }
};