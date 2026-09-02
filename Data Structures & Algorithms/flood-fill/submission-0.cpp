class Solution {
public:
    int m, n;
    int originalColor;
    int newColor;

    void dfs(vector<vector<int>>& image, int r, int c) {
        
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        
        if (image[r][c] != originalColor)
            return;

      
        image[r][c] = newColor;

      
        dfs(image, r + 1, c); 
        dfs(image, r - 1, c); 
        dfs(image, r, c + 1); 
        dfs(image, r, c - 1); 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        originalColor = image[sr][sc];
        newColor = color;


        if (originalColor == newColor)
            return image;

        dfs(image, sr, sc);

        return image;
    }
};