class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        vector<int> result;
        for(auto it: mp)
        {
            if(it.second <= k) 
            {
                for(int i=0;i<it.second;i++) result.push_back(it.first);
            }
            else 
            {
                for(int i=0;i<k;i++) result.push_back(it.first);
            }
        }
        return result;
    }
};