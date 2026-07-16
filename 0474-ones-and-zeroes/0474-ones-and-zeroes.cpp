class Solution {
public:
    int solve(int idx,int m,int n,vector<string>& strs,vector<vector<vector<int>>>&dp)
    {
        if(idx >= strs.size()) return 0;
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        int take = 0;
        int not_take = solve(idx+1,m,n,strs,dp);
        int o = 0;
        int z = 0;
        for(int i=0;i<strs[idx].length();i++)
        {
           if(strs[idx][i] == '1') o++;
           else z++;
        }
        if(z <= m && o <= n) take = 1 + solve(idx+1,m-z,n-o,strs,dp);
        return dp[idx][m][n] = max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,strs,dp);
    }
};

