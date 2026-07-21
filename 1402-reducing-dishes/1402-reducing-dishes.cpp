class Solution {
public:
    int solve(int idx,int dis,vector<int>& satisfaction,vector<vector<int>>& dp)
    {
        if(idx >= satisfaction.size()) return 0;
        if(dp[idx][dis] != -1) return dp[idx][dis];
        int take = 0;
        int not_take = 0;
        take = satisfaction[idx]*dis + solve(idx+1,dis+1,satisfaction,dp);
        not_take = solve(idx+1,dis,satisfaction,dp);
        return dp[idx][dis] = max(take,not_take);

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        int ans = solve(0,1,satisfaction,dp);
        return ans >= 0 ? ans : 0;
    }
};