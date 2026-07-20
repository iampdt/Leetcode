class Solution {
public:
    int solve(int idx,int k,vector<int>& slices,vector<vector<int>>& dp)
    {
        if(idx >= slices.size()) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        int not_take = solve(idx+1,k,slices,dp);
        int take = 0;
        if(k>0) take = slices[idx] + solve(idx+2,k-1,slices,dp);
        return dp[idx][k] = max(take,not_take);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> slices2;
        for(int i=1;i<n;i++) slices2.push_back(slices[i]);
        slices.pop_back();
        vector<vector<int>> dp1(n+1,vector<int>(n/3+1,-1));
        vector<vector<int>> dp2(n+1,vector<int>(n/3+1,-1));
        return max(solve(0,n/3,slices,dp1),solve(0,n/3,slices2,dp2));
    }
};