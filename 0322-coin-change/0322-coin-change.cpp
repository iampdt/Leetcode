class Solution {
public:
    long long solve(int index,vector<int>&coins,vector<vector<long long>>&dp,int amount)
    {
        if(index >= coins.size() || amount <= 0)
        {
            if(amount == 0) return 0;
            else return INT_MAX;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        long long take = INT_MAX;
        long long not_take = solve(index+1,coins,dp,amount);
        if(coins[index]<=amount)
        {
            take = 1LL + 1LL*solve(index,coins,dp,amount-coins[index]);
        }
        return dp[index][amount] = min(1LL*take,1LL*not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<long long>> dp(coins.size()+1,vector<long long>(amount + 1,-1));
        int ans = (int)solve(0,coins,dp,amount);
        return  ans == INT_MAX ? -1 : ans;
    }
};