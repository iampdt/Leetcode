class Solution {
public:
    long long solve(int index,vector<int>&coins,vector<vector<long long>>&dp,int amount)
    {
        if(index >= coins.size() || amount <= 0)
        {
            if(amount == 0) return 1;
            else return 0;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        long long take = 0;
        long long not_take = solve(index+1,coins,dp,amount);
        if(coins[index]<=amount)
        {
            take = 1*solve(index,coins,dp,amount-coins[index]);
        }
        return dp[index][amount] = take + not_take;
            }
    int change(int amount,vector<int>& coins) {
        vector<vector<long long>> dp(coins.size()+1,vector<long long>(amount + 1,-1));
        int ans = (int)solve(0,coins,dp,amount);
        return ans;
    }
};