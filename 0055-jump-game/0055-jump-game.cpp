class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = nums[0];

        for(int i=0;i<nums.size();i++)
        {
           if(maxIdx < i) return false;
            maxIdx = max(maxIdx,nums[i] + i);
        }
        return true;
    }
};