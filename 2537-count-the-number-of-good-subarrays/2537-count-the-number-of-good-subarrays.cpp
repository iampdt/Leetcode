class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        int i=0;
        long long cnt = 0;
        unordered_map<long long,long long> mp;
        long long sum = 0;


        for(int j=0;j<nums.size();j++)
        {
           sum+=mp[nums[j]]; 
           mp[nums[j]]++;
           while(sum>=k)
           {
             cnt+= nums.size() - j;
             mp[nums[i]]--;
             sum-=mp[nums[i]];
             i++;
           }
           
        }
        return cnt;
    }
};