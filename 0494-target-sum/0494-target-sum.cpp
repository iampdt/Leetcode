class Solution {
public:
    int solve(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(sum < 0) return 0;
        if (idx == nums.size()) {
            return sum == 0 ? 1 : 0;
        }
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        int take = solve(idx + 1, sum - nums[idx], nums, dp);
        int not_take = solve(idx + 1, sum, nums, dp);
        return (dp[idx][sum] = (take + not_take));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
       if (abs(target) > sum || (sum + target) % 2 != 0 || (sum + target) < 0) {
            return 0;
        }
        return solve(0, (sum + target) / 2, nums, dp);
    }
};