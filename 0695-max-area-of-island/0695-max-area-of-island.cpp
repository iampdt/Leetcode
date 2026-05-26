class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int &cnt)
    {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j] == 0 || vis[i][j] == 1) return;
        vis[i][j] = 1;
        cnt++;
        dfs(i,j+1,grid,vis,cnt);
        dfs(i-1,j,grid,vis,cnt);
        dfs(i+1,j,grid,vis,cnt);
        dfs(i,j-1,grid,vis,cnt);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        int max_area = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    dfs(i,j,grid,vis,cnt);
                    max_area = max(max_area,cnt);
                    cnt = 0;
                }
            }
        }

        return max_area;
    }
};