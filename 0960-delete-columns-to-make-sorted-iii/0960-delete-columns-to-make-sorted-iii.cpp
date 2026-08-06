class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n = strs[0].length();
        vector<int> dp(n,1);
        int len = 1;

        for(int i=0;i<n;i++)
        {
           
            for(int prev=0;prev<i;prev++)
            {
                 bool ok = true;
                for(int k=0;k<strs.size();k++)
                {
                    if(strs[k][prev] > strs[k][i]) ok = false;
                }
                if(ok) dp[i] = max(dp[i],1+dp[prev]);
            }
            
            len = max(len,dp[i]);
        }

        return n-len;
    }
};