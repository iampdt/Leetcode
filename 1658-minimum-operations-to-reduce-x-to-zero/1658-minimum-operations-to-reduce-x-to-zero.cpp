class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total_sum = accumulate(nums.begin(),nums.end(),0);
        int target = total_sum - x;
        if(target < 0) return -1;
        int i = 0;
        int ans = -1;
        int sum =0;

        for(int j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            while(sum > target)
            {
                sum -= nums[i];
                i++;
            }
            if(sum == target) ans = max(ans, j-i+1);
        }
        
        return ans == -1 ? ans : nums.size() - ans;
    }
};