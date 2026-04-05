class Solution {
public:

    int solve(int start,int end,int k,vector<int>&cost, vector<vector<int>>&dp)
    {
        if(k == 0) return 0;
        if(start > end) return 1e9;
        if(dp[start][k] != -1) return dp[start][k];

        int take = solve(start+2,end,k-1,cost,dp) + cost[start];
        int not_take = solve(start+1,end,k,cost,dp);

        return dp[start][k] = min(take,not_take);
    }
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k>n/2) return -1;
        if(k==0) return 0;
        vector<int> cost(n,0);

        for(int i=0;i<n;i++)
        {
            int pre = nums[abs(i-1+n)%n];
            int next = nums[(i+1)%n];
            int curr = nums[i];
            int target = max(pre,next) + 1;
            cost[i] = max(0,target - curr);
        } 

        vector<vector<int>> dp1(n,vector<int>(k+1,-1));
        vector<vector<int>> dp2(n,vector<int>(k+1,-1));

        int path1 = solve(0,n-2,k,cost,dp1);
        int path2 = solve(1,n-1,k,cost,dp2);

        int final_ans = min(path1,path2);
        return final_ans >=1e9 ? -1 : final_ans;
     
        
        

        
    }
};