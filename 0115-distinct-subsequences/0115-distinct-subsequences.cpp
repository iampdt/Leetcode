class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>& dp)
    {
         if(j==t.size()) return 1;
        if(i>=s.size() || j>t.size()) return 0;
       
        if(dp[i][j] != -1) return dp[i][j];
        long long op1 = 1LL*solve(i+1,j,s,t,dp);
        long long op2 = 0;
        if(s[i] == t[j]) op2 = 1LL*solve(i+1,j+1,s,t,dp);
        return dp[i][j] = 1LL*op1 + 1LL*op2;
    }
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return int(solve(0,0,s,t,dp));
    }
};