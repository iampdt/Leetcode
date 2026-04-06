
const int mod = 1e9 + 7;

class Solution {
public:
    int solve(int idx,int last_val,vector<int>&v,vector<int>&digitSum,vector<vector<int>>&dp)
    {
        if (last_val > 5000) return 0;
        if(idx == digitSum.size()) return 1;
        if(dp[idx][last_val] != -1) return dp[idx][last_val];
        int total_ways = solve(idx,last_val+1,v,digitSum,dp);
        if(v[last_val] == digitSum[idx]) total_ways += (solve(idx+1,last_val,v,digitSum,dp))%mod;
        return dp[idx][last_val] = total_ways%mod;
    }
    int countArrays(vector<int>& digitSum) {
         vector<int> v(5005,0);
        for(int i=0;i<5001;i++)
        {
            int num = i;
            int sum = 0;
            while(num > 0)
            {
                sum += num%10;
                num/=10;
            }
            v[i] = sum;
        }

        vector<vector<int>> dp(digitSum.size()+1,vector<int>(5005,-1));
        return solve(0,0,v,digitSum,dp);
        

        
    }
};