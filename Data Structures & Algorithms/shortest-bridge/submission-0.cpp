class Solution {
public:

    int n;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<pair<int,int>> q;

    void dfs(int r, int c, vector<vector<int>>& grid)
    {

        if(r < 0 || r >= n || c < 0 || c >= n)
            return;

        if(grid[r][c] != 1)
            return;

        grid[r][c] = 2;


        q.push({r, c});


        for(int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            dfs(nr, nc, grid);
        }
    }

    int shortestBridge(vector<vector<int>>& grid)
    {
        n = grid.size();



        bool found = false;

        for(int i = 0; i < n && !found; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                    found = true;
                    break;
                }
            }
        }



        int distance = 0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto [r, c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    
                    if(nr < 0 || nr >= n || nc < 0 || nc >= n)
                        continue;

                    
                    if(grid[nr][nc] == 1)
                        return distance;

                    
                    if(grid[nr][nc] == 0)
                    {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }

            distance++;
        }

        return -1;
    }
};