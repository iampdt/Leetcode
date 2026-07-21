class Solution {
public:
    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp)
    {
        if(i >= nums1.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = 1e9;
        int not_take = 1e9;
        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];
        if(j) swap(prev1,prev2);
        if(nums1[i] > prev1 && nums2[i] > prev2) not_take = solve(i+1,0,nums1,nums2,dp);
        if(nums1[i] > prev2 && nums2[i] > prev1)
        {
            take = 1 + solve(i+1,1,nums1,nums2,dp);
        }
        return dp[i][j] = min(take,not_take);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return min(solve(1,0,nums1,nums2,dp),1+solve(1,1,nums1,nums2,dp));
    }
};