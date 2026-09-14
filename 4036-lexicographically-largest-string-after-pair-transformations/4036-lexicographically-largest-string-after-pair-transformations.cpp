class Solution {
public:
    int helper(int n) {
        if (n <= 1)
            return 1;

        int lower = 1 << (31 - __builtin_clz(n));
        return lower > 33554432 ? 33554432 : lower;
    }
    vector<string> largestString(vector<int>& nums) {

        vector<string> ans;
        unordered_map<int, char> mp;

        for (int i = 0; i < 26; i++) {
            mp[1 << i] = 'a' + i;
        }

        for (int i = 0; i < nums.size(); i++) {

            int original_val = nums[i];
            string temp = "";
            while(original_val > 0)
            {
                int val = helper(original_val);
                temp += mp[val];
                original_val = original_val - val;
            }

            ans.push_back(temp);

        }
        return ans;
    }
};