class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        // if(nums[0] > nums[1]) return nums[0];
        // if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums[nums.size() - 1];

        int low = 0;
        int high = nums.size()-1;
        // int ans = -1;

        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[mid + 1]) high = mid;
            else low = mid + 1;


        }
      return low;
    }
};