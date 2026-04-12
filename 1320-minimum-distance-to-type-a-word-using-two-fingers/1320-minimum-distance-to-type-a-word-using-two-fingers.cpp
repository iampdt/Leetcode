class Solution {
private:
    int getDistance(int c1, int c2) {
        int row1 = c1 / 6, col1 = c1 % 6;
        int row2 = c2 / 6, col2 = c2 % 6;
        return abs(row1 - row2) + abs(col1 - col2);
    }

public:
    int minimumDistance(string word) {
        int n = word.length();
        if (n <= 2) return 0; 
        vector<int> dp(26, 0);

        for (int i = 0; i < n - 1; i++) {
            int u = word[i] - 'A';
            int v = word[i + 1] - 'A';
            vector<int> next_dp(26, 1e9);

            for (int c = 0; c < 26; c++) {
                if (dp[c] == 1e9) continue; // Skip unreachable states
                next_dp[c] = min(next_dp[c], dp[c] + getDistance(u, v));
                next_dp[u] = min(next_dp[u], dp[c] + getDistance(c, v));
            }
            dp = next_dp;
        }

        int min_cost = 1e9;
        for (int cost : dp) {
            min_cost = min(min_cost, cost);
        }

        return min_cost;
    }
};