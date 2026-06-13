class Solution {
public: 
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || vis[i][j] == 1 || grid[i][j] == '0') return;
        vis[i][j] = 1;
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0) 
                {
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};