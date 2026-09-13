class Solution {
public:
     int solve(int idx, int remaining_sum, const vector<vector<pair<int, int>>>& all_options, vector<vector<int>>& memo) {
        if (remaining_sum == 0) return 0; // Reached exact sum
        if (idx == all_options.size()) return 1e9; // Ran out of elements
        if (memo[idx][remaining_sum] != -1) return memo[idx][remaining_sum];
        int min_ops = solve(idx + 1, remaining_sum, all_options, memo);
        for (const auto& opt : all_options[idx]) {
            int val = opt.first;
            int cost = opt.second;
            if (remaining_sum >= val) {
                int res = solve(idx + 1, remaining_sum - val, all_options, memo);
                if (res != 1e9) {
                    min_ops = min(min_ops, cost + res);
                }
            }
        }
        
        return memo[idx][remaining_sum] = min_ops;
    }
    int minOperations(vector<int>& nums, int sum) {
       int n = nums.size();
       vector<vector<pair<int, int>>> all_options(n);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            all_options[i].push_back({x, 0});
            
            int val = x, cost = 0;
            while (val * 2 <= sum) {
                val *= 2;
                cost++;
                all_options[i].push_back({val, cost});
            }
            
            val = x, cost = 0;
            while (val > 0) {
                val /= 2;
                cost++;
                if (val > 0) {
                    all_options[i].push_back({val, cost});
                }
            }
        }
        vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
        int ans = solve(0, sum, all_options, memo);
        
        return ans == 1e9 ? -1 : ans;
    }
};