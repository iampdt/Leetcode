class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int len =2;len<=n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j = i+len-1;
                dp[i][j] = 1e9;
                for(int k = i;k<j;k++)
                {
                    int a = *max_element(arr.begin()+i,arr.begin()+k+1);
                    int b = *max_element(arr.begin()+k+1,arr.begin()+j+1);
                    dp[i][j] = min(dp[i][j],(a*b + dp[i][k] + dp[k+1][j]));
                }
            }
        }
        return dp[0][n-1];
    }
};