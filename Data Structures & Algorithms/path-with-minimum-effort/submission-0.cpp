class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        while(!pq.empty())
        {
            auto[effort, cell] = pq.top();
            pq.pop();
            auto[r, c] = cell;
            if(r==n-1 && c == m-1) return effort;
            for(int i=0;i<4;i++)
            {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m )
                {
                    int edgeWeight = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(effort, edgeWeight);

                    if(newEffort < dist[nr][nc])
                    {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};