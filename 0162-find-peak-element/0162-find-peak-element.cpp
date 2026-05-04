class Solution {
public: 
    bool helper(vector<int>&nums,int index)
    {
        if(index == 0 && nums[index] > nums[index + 1]) return true;
        else if(index == nums.size()-1 && nums[index] > nums[index - 1]) return true;
        else if(nums[index] > nums[index + 1] && nums[index] > nums[index - 1]) return true;
        return false;
    }
    int findPeakElement(vector<int>& nums) {

        if(nums.size() == 1) return 0;
        // if(nums[0] > nums[1]) return nums[0];
        // if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums[nums.size() - 1];

        int low = 0;
        int high = nums.size();
        // int ans = -1;

        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(helper(nums,mid)) return mid;
            else if(nums[mid] >= nums[mid + 1]) high = mid;
            else low = mid + 1;


        }
      return -1;
        
    }
};