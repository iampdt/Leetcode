class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j!=0) dp[i][j] = 0;
                else if(j==0) dp[i][j] = 1;

                else
                {
                    dp[i][j] = dp[i-1][j];
                    if(s[i-1] == t[j-1]) dp[i][j] = 1LL*dp[i][j] + 1LL*dp[i-1][j-1];
                }
            }
        }
        return (int)dp[n][m];
    }
};