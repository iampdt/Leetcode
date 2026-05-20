class Solution {
public:
    int solve(int index,int op,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(index >= prices.size()) return 0;
        if(dp[index][op]!=-1) return dp[index][op];
        int buy=0;
        int sell=0;
        int do_nothing = solve(index+1,op,prices,dp);
        if(op == 1) buy = solve(index + 1,0,prices,dp) - prices[index];
        else sell = solve(index+1,1,prices,dp) + prices[index];

        return dp[index][op] = max({buy,sell,do_nothing});

    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,dp);
        
    }
};