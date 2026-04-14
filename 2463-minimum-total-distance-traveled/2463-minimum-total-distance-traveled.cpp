class Solution {
public:
    long long solve(int i, int j,vector<int>&robot,vector<vector<int>>&factory,vector<vector<long long>>&dp)
    {
        if(i>=robot.size()) return 0;
        if(j==factory.size()) return 1e18;
        if(dp[i][j] != -1) return dp[i][j];
        long long ans = solve(i, j + 1, robot, factory, dp);
        long long dist = 0;

        for(int k = 1;k<=factory[j][1] && i+k-1<robot.size();k++)
        {
             dist += abs(robot[i+k-1] - factory[j][0]);
             ans = min(ans, dist + solve(i+k,j+1,robot,factory,dp));
            
        } 
        return dp[i][j] = ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        vector<vector<long long>> dp(robot.size()+1,vector<long long>(factory.size()+1,-1));
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        return solve(0,0,robot,factory,dp);

        
    }
};