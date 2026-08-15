class Solution {
public:
    int countSubstrings(string s) {
       
       int n = s.length();
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       for(int i=0;i<n;i++) dp[i][i] = 1;
       int count = 0;

       for(int len=2;len<=n;len++)
       {
        for(int i=0;i+len-1<n;i++)
        {
            int j = len+i-1;
            // Transition 
            if(len == 2 && s[i] == s[j]) dp[i][j] = 1;
            else if(s[i] == s[j] && dp[i+1][j-1] == 1) dp[i][j] = 1;
        }
       }
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            count += dp[i][j];
        }
       }
      return count;
    }
};