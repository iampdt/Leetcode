class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++) dp[i][i] = nums[i];
        for(int len=2;len<=n;len++)
        {
            for(int i=0;len+i-1<n;i++)
            {
                int j = len+i-1;
                // max player A score - max player B score
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }

        return dp[0][n-1] >= 0;
    }
};