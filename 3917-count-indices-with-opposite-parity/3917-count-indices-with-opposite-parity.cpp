class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        vector<int> ans;

        for(int i=0;i<nums.size();i++)
        {
            int cnt = 0;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]%2 != nums[j]%2) cnt++;
            }
            ans.push_back(cnt);
        }

        return ans;
        
    }
};