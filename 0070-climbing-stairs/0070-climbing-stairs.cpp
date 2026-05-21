class Solution {
public:
    int solve(int index,int n,vector<int>&dp)
    {
        if(index > n) return 0;
        if(index == n) return 1;

        if(dp[index]!= -1) return dp[index];
        int one = solve(index+1,n,dp);
        int two = solve(index+2,n,dp);

        return dp[index] = one + two;
        
    }
    int climbStairs(int n) {
      vector<int> dp(n+1,-1);
      return solve(0,n,dp);  
    }
};