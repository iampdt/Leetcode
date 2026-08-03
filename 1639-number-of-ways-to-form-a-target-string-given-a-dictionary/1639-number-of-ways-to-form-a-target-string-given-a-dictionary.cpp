class Solution {
public:
    int mod = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        
        unordered_map<int,unordered_map<char,int>> mp;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                mp[j][words[i][j]]++;
            }
        }
        int t = target.length();
        int L = words[0].size();
        vector<vector<long long>> dp(L + 1, vector<long long>(t + 1, 0));
        for (int i = 0; i <= L; i++) dp[i][0] = 1;
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= t; j++) {
                dp[i][j] = dp[i - 1][j];
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * mp[i - 1][target[j - 1]]) % mod;
            }
        }
        return (int)dp[L][t];
    }
};