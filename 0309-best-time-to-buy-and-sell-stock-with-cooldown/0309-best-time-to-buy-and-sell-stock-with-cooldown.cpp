class Solution
{
public:
    int solve(int i, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int take = 0;
        int not_take = 0;
        // buy sell do_nothing
        int do_nothing = solve(i + 1,buy ,prices, dp);
        if (buy)
            take = max(do_nothing,solve(i + 1, 0, prices, dp) - prices[i]);
        else
            not_take = solve(i+2,1,prices,dp) + prices[i];
        return dp[i][buy] = max({take, not_take, do_nothing});
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};