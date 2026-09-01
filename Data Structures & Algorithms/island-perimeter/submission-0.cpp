class Solution {
public:
    int BFS(vector<vector<int>>& grid, int r,int c, vector<vector<int>>& visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        q.push({r,c});
        visited[r][c] = 1; 
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        int cnt =0;

        
        while(!q.empty())
        {
            auto[row, col] = q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];



                if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                    grid[nr][nc] == 0)
                {
                    cnt++;
                }

                else if (visited[nr][nc] == -1 && grid[nr][nc] == 1)
                {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n, -1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j] == -1 && grid[i][j] == 1)
                {
                    return BFS(grid, i, j, visited);
                }
            }
        }
    }
};