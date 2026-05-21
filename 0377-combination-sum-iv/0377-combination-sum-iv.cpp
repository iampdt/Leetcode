class Solution {
private:
    int solve(vector<int>& nums, int target, vector<long long>& dp){
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];

        long long ways = 0;

        for(int num : nums){
            ways += solve(nums, target - num, dp);
        }

        return dp[target] = ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};