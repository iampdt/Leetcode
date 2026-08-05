class Solution {
public:
    int solve(int idx, int prev, map<pair<int, int>, int>& memo,
              vector<int>& nums, vector<int>& temp) {
        if (idx >= nums.size())
            return 0;
        if (memo.find({idx, prev}) != memo.end())
            return memo[{idx, prev}];
        int op1 = 1e9;
        int op2 = 1e9;

        auto it = upper_bound(temp.begin(), temp.end(), prev);
        if (nums[idx] > prev)
            op1 = 0 + solve(idx + 1, nums[idx], memo, nums, temp);
        if (it != temp.end())
            op2 = 1 + solve(idx + 1, *it, memo, nums, temp);
       return memo[{idx, prev}] = min(op1, op2);
    }
    int makeArrayIncreasing(vector<int>& nums, vector<int>& arr2) {
        set<int> st;
        vector<int> temp;
        for (int i = 0; i < arr2.size(); i++)
            st.insert(arr2[i]);
        for (auto it : st)
            temp.push_back(it);
        map<pair<int, int>, int> memo;
        // for(int i=0;i<n;i++)
        // {
        //    for(int j=0;j<m;j++)
        //    {
        //      dp[i][j] =
        //    }
        // }
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        // return dp[n-1];
        int res = solve(0, -1, memo, nums, temp);
        return res >= 1e9 ? -1 : res;
    }
}; //