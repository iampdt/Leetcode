/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    int solve(int idx,int sum,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(idx >= nums.size() || sum < 0) return 0;
        if(sum == 0) return 1;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool take = solve(idx+1,sum-nums[idx],nums,dp);
        bool not_take = solve(idx+1,sum,nums,dp);
        return dp[idx][sum] = take + not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(0,sum/2,nums,dp);
    }

};
// @lc code=end

