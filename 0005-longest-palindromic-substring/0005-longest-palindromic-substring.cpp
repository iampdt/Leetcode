class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for (int length = 1; length <= n; length++) {
        for (int i = 0; i + length - 1 < n; i++) {
            int j = i + length - 1;
            if (length == 1)
                dp[i][j] = true;
            else if (length == 2)
                dp[i][j] = (s[i] == s[j]);
            else
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
        }
    }
        int x = 0;
        int y = 0;
        int maxi = INT_MIN;
        for(int i=0;i<=n;i++)
        {
           for(int j=0;j<=n;j++)
           {
             if(dp[i][j] && i!=j) 
             {
                int diff = abs(j-i);
                if(diff > maxi)
                {
                    maxi = diff;
                    x = i;
                    y = j;
                }
             }
           }
        }
        return s.substr(x,y-x+1);
    }
};