class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [cost, r, c] = pq.top();
            pq.pop();

            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n)
                {
                    int newCost = max(cost, grid[nr][nc]);
                    if (newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, nr, nc});
                    }
                }
            }

        }

        return dist[n-1][n-1];
    }
};
