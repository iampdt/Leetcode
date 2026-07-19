class Solution {
public:
    int solve(int idx,int diff,vector<int>& rods,vector<vector<int>>& dp)
    {
        if(idx == rods.size()) return diff == 0 ? 0 : -1e9;
        if(dp[idx][diff] != -1) return dp[idx][diff];

        int not_take = solve(idx+1,diff,rods,dp);
        int put_on_taller = rods[idx] + solve(idx+1,diff+rods[idx],rods,dp);
        int put_on_smaller = 0;
        if(rods[idx] - diff > 0) put_on_smaller = rods[idx] - diff + solve(idx+1,rods[idx]-diff,rods,dp);
        else put_on_smaller = solve(idx+1,diff-rods[idx],rods,dp);
        return dp[idx][diff] = max({not_take,put_on_smaller,put_on_taller});
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = accumulate(rods.begin(),rods.end(),0);
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        int result = solve(0, 0, rods, dp);
        return result < 0 ? 0 : result;
    }
};