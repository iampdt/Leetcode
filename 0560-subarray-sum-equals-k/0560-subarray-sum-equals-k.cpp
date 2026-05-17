class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1) return k == nums[0] ? 1 : 0;
        vector<int> prefix(nums.size(),0);
        int cnt = 0;
        int current_sum = 0;
        unordered_map<int,int> mp;
        prefix[0]=nums[0];
        mp[0]++;
        for(int i=0;i<nums.size();i++)
        {
            current_sum+=nums[i];
            if(mp.find(current_sum-k)!=mp.end()) cnt+=mp[current_sum-k];
            mp[current_sum]++;
        }
        return cnt;
    }
};