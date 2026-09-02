class Solution {
public:
     int m, n;

    void bfs(vector<vector<int>>& heights,
             queue<pair<int,int>>& q,
             vector<vector<bool>>& vis) {

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    !vis[nr][nc] &&
                    heights[nr][nc] >= heights[r][c]) {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;

        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            pq.push({i, 0});
        }

        for (int j = 0; j < n; j++) {
            pacific[0][j] = true;
            pq.push({0, j});
        }

        for (int i = 0; i < m; i++) {
            atlantic[i][n - 1] = true;
            aq.push({i, n - 1});
        }

        for (int j = 0; j < n; j++) {
            atlantic[m - 1][j] = true;
            aq.push({m - 1, j});
        }

        
        bfs(heights, pq, pacific);
        bfs(heights, aq, atlantic);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};