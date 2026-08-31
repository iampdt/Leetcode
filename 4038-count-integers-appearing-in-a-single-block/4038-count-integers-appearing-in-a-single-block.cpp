class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        unordered_map<int,vector<int>> mp;
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
            {
               mp[nums[i]].push_back(i);
            }

        for(auto it: mp)
            {
                bool flag = true;
                for(int i=0;i<it.second.size()-1;i++)
                    {
                        if(it.second[i] != it.second[i+1]-1) flag = false;
                    }
                if(flag) cnt++;
            }
        return cnt;
    }
};