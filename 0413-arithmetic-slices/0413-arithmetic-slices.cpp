class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int result = 0;
        for (int i = 1; i < n; i++) {

                long long d = (long long)nums[i] - nums[i-1];
                int prev = 0;
                auto it = dp[i-1].find(d);
                if (it != dp[i-1].end()) prev = it->second;
                dp[i][d] += prev + 1;
                result += prev;
        }
        return result;
    }
};