class Solution {
public:
    int solve(int index,vector<int>&nums,vector<int>&dp)
    {
        if(index >= nums.size()) return INT_MAX;
        if(index == nums.size()-1) return 0;
        if(dp[index] != INT_MAX) return dp[index];

        for(int i=1;i<=nums[index];i++)
        {
            dp[index] = min(1LL*dp[index],1LL*1+1LL*solve(index+i,nums,dp));
        }

         
        return dp[index];
    }
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int> dp(nums.size()+1,INT_MAX);
        return solve(0,nums,dp);
    }
};