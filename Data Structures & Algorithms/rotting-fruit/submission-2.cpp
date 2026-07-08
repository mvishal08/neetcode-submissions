class Solution {
public:
    void BFS(vector<vector<int>>& grid, vector<vector<int>>& visited,queue<pair<int, int>>& q,int& ans)
    {
        int m = grid.size();
        int n = grid[0].size();
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};
        
        while(!q.empty())
        {
            bool changed = false;
            int size = q.size();
            
            
            for(int k=0; k<size;k++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {   
                    int nr = r + drow[i];
                    int nc = c + dcol[i];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc]==1)
                    {
                        grid[nr][nc] = 2;
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                        changed = true;
                    }
                
                }
            }
            if(changed) ans++;
            

        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        queue<pair<int, int>>q;
        vector<vector<int>>visited(m, vector<int>(n, 0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i, j});
                }
            }
        }
        BFS(grid, visited, q, ans);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
