class Solution {
public:
    void BFS(vector<vector<int>>& grid,int row, int col,vector<vector<int>>& visited,vector<int>& ans)
    {
        int count = 1;
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>>q;
        q.push({row, col});
        visited[row][col] = 1;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1 &&
                    !visited[nr][nc])
                {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                    count++;
                }
            }
            ans.push_back(count);

        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int>ans;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 1 && !visited[i][j])
                {
                    count++;
                    BFS(grid,i,j, visited, ans);
                }
            }
        }
        sort(ans.rbegin(), ans.rend());
        if(ans.size()==0) return 0;
        else return ans[0];
    }
};