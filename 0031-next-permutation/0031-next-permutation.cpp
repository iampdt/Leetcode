class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int j = nums.size() - 2;
        while(j>=0 && nums[j] >= nums[j+1]) j--;
      
        if(j>=0)
        {
        int k = nums.size() - 1;
        while(nums[j] >= nums[k]) k--;
        swap(nums[j],nums[k]);
        }
        sort(nums.begin() + j + 1 ,nums.end());
    }
};