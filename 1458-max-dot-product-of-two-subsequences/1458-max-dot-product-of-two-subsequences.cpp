class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int take = a[i] * b[j];
                if (i > 0 && j > 0) take += max(dp[i - 1][j - 1], 0);
                dp[i][j] = take;
                if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};