class Solution {
private:
    int solve(vector<int> &prices,int index,bool buy,vector<vector<int>> &dp,int fee){
        int n = prices.size();

        if(index>=n) return 0;

        if(dp[index][buy]!=-1) return dp[index][buy];

        int profit =0;

        if(buy){

            int buyStock = -prices[index] + solve(prices,index+1,0,dp,fee);

            int skip = solve(prices,index+1,1,dp,fee);

            profit = max(buyStock,skip);

        }else{

            int sellStock = prices[index] + solve(prices,index+1,1,dp,fee) - fee;

            int skip = solve(prices,index+1,0,dp,fee);

            profit = max(sellStock,skip);
        }

        return dp[index][buy]=profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        return solve(prices,0,1,dp,fee);
    }
};