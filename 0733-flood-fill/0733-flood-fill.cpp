class Solution {
public:
    int rows[4] = {-1, 1, 0, 0};
    int cols[4] = {0, 0, -1, 1};
    int n, m;
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m); }
    void DFS(int r, int c, int& matchingColor, int& color,
             vector<vector<int>>& image) {
        for (int k = 0; k < 4; k++) {
            int newR = r + rows[k];
            int newC = c + cols[k];
            if (isValid(newR, newC) && (image[newR][newC] == matchingColor)) {
                image[newR][newC] = color;
                DFS(newR, newC, matchingColor, color, image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (image[sr][sc] == color)
            return image;
        int matchingColor = image[sr][sc];
        n = image.size();
        m = image[0].size();
        image[sr][sc] = color;
        DFS(sr, sc, matchingColor, color, image);
        return image;
    }
};