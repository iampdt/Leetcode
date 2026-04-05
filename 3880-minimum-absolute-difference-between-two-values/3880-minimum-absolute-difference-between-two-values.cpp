class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {

        vector<int> one;
        vector<int> two;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                one.push_back(i);
            else if (nums[i] == 2)
                two.push_back(i);
        }

        for (int i = 0; i < one.size(); i++) {
            for (int j = 0; j < two.size(); j++) {
                ans = min(ans, abs(one[i] - two[j]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};