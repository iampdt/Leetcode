class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        dp[1][1] = 1; 
        
        for (int i = 1; i <= n; i++) {      
            for (int j = 1; j <= i; j++) {   
                
                if (dp[i][j] == 1e9) continue; 
                if (i + j <= n) {
                    dp[i + j][j] = min(dp[i + j][j], dp[i][j] + 1);
                }
                if (j != i) {
                    dp[i][i] = min(dp[i][i], dp[i][j] + 1);
                }
            }
        }
        int ans = 1e9;
        for (int j = 1; j <= n; j++) {
            ans = min(ans, dp[n][j]);
        }
        
        return ans;
    }
};