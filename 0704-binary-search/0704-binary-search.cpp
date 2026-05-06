class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size();

        while(low < high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] < target) low = mid + 1;
            else high = mid; 
        }

        return ((low < nums.size()) && (nums[low] == target)) ? low : -1;
    }
};