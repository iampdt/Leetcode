class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        unordered_map<int, int> dp;
        
        dp[-1] = 0; 
        
        for (int i = 0; i < arr1.size(); i++) {
            unordered_map<int, int> next_dp;
            
            for (auto it : dp) {
                int prev_val = it.first;
                int ops = it.second;
                if (arr1[i] > prev_val) {
                    if (next_dp.find(arr1[i]) == next_dp.end()) {
                        next_dp[arr1[i]] = ops;
                    } else {
                        next_dp[arr1[i]] = min(next_dp[arr1[i]], ops);
                    }
                }
                auto upper = upper_bound(arr2.begin(), arr2.end(), prev_val);
                if (upper != arr2.end()) {
                    int replacement_val = *upper;
                    if (next_dp.find(replacement_val) == next_dp.end()) {
                        next_dp[replacement_val] = ops + 1;
                    } else {
                        next_dp[replacement_val] = min(next_dp[replacement_val], ops + 1);
                    }
                }
            }
            if (next_dp.empty()) {
                return -1;
            }
            
            dp = next_dp;
        }
        
        int min_ops = 1e9;
        for (auto it : dp) {
            min_ops = min(min_ops, it.second);
        }
        
        return min_ops;
    }
};