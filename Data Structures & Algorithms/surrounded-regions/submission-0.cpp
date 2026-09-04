class Solution {
public:

    void BFS(int row, int col,vector<vector<char>>& board,vector<vector<int>>& visited)
    {
        int m = board.size();
        int n = board[0].size();

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
                    board[nr][nc] == 'O' && !visited[nr][nc])
                {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }

            }
    
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int j=0;j<n;j++)
        {
            if(!visited[0][j] && board[0][j]=='O')
            {
                BFS(0, j, board,visited);
            }
            if(!visited[m-1][j] && board[m-1][j]=='O')
            {
                BFS(m-1, j, board,visited);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!visited[i][0] && board[i][0]=='O')
            {
                BFS(i, 0, board,visited);
            }
            if(!visited[i][n-1] && board[i][n-1]=='O')
            {
                BFS(i, n-1, board,visited);
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};