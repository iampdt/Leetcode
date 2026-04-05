class Solution {
public:
    int solve(int i,int j,int x,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        if(i>=grid.size() || j>=grid[0].size()) return 1e9;
        if(i == grid.size()-1 && j == grid[0].size()-1) return x ^grid[i][j];
        if(dp[i][j][x] != -1) return dp[i][j][x];

        int right = solve(i,j+1,x^grid[i][j],grid,dp);
        int down = solve(i+1,j,x^grid[i][j],grid,dp);

        return dp[i][j][x] = min(right,down);
    }
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1,vector<int>(1024,-1)));
        return solve(0,0,0,grid,dp);
        
    }
};