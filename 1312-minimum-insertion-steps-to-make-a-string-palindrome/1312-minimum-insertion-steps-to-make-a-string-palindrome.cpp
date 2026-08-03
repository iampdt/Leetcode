class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.length();
        vector<vector<int>> isPal(n+1,vector<int>(n+1,0));

        for(int len = 1;len <= n; len++)
        {
            for(int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                if (len == 1) { isPal[i][j] = 1; }
                else if(s[i] == s[j]) isPal[i][j] = 2 + isPal[i+1][j-1];
                else isPal[i][j] = max(isPal[i+1][j],isPal[i][j-1]);

            }
        }

        return n - isPal[0][n-1];
    }
};