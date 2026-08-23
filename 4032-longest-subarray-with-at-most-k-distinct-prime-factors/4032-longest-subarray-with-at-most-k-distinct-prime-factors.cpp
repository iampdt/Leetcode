class Solution {
public:
    map<int, set<int>> factorize(vector<int>& nums) {
        map<int, set<int>> primeExponents;
        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            for (int divisor = 2; divisor * divisor <= number; divisor++) {
                while (number % divisor == 0) {
                    primeExponents[nums[i]].insert(divisor);
                    number /= divisor;
                }
            }

            if (number > 1)
                primeExponents[nums[i]].insert(number);
        }
        return primeExponents;
    }
    int longestSubarray(vector<int>& nums, int k) {
        map<int, set<int>> factors = factorize(nums);
        unordered_map<int,int> mp;
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            for (int prime : factors[nums[right]]) {
                mp[prime]++;
            }
            while (mp.size() > k) {
                for (int prime : factors[nums[left]]) {
                    mp[prime]--;
                    if (mp[prime] == 0) {
                        mp.erase(prime);
                    }
                }
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    
    }
};