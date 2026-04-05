class Solution {
public:
    
    int solve(int i, vector<int>&nums,vector<int>&dp)
    {
        if(i>=nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
       
        int take = 0;
        int not_take = 0;
        take = solve(i+2,nums,dp) + nums[i];
        not_take = solve(i+1,nums,dp);

        return dp[i] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);

        vector<int> copy;
        for(int i=1;i<n;i++)
        {
            copy.push_back(nums[i]);
        }
        nums.pop_back();

        return max(solve(0,nums,dp1),solve(0,copy,dp2));
    }
};