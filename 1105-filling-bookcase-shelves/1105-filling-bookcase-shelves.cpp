class Solution {
public:
    int solve(int idx,vector<vector<int>>&books,int s,vector<int>&dp)
    {
        if(idx >= books.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int current_width = 0;
        int max_height = 0;
        int min_height = INT_MAX;


        for(int i = idx;i<books.size();i++)
        {
           current_width += books[i][0];
           max_height = max(max_height,books[i][1]);
           if(current_width > s) break;
           int max_height_till_now = max_height + solve(i+1,books,s,dp);
           min_height = min(min_height,max_height_till_now);
        }

        return dp[idx] = min_height;
    }
    int minHeightShelves(vector<vector<int>>& books, int s) {
       int n = books.size();
       vector<int> dp(n+1,-1);
       return solve(0,books,s,dp);
    }
};