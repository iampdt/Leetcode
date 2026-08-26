class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int uniqueCount = nums.size();
        int maxInWindow = 0;
        for (int i = 0; i < uniqueCount; i++) {
            int windowEnd = nums[i] + n - 1;
            int count = (int)(upper_bound(nums.begin(), nums.end(), windowEnd) - nums.begin()) - i;
            maxInWindow = max(maxInWindow, count);
        }
        return n - maxInWindow;
    }
};