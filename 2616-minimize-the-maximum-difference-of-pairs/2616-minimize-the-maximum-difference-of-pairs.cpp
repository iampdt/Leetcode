class Solution {
public:
    int helper(vector<int>&nums,int p,int mid)
    {
        int cnt = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(abs(nums[i] - nums[i-1]) <= mid) { cnt++; i++;}
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        
        int low = 0;
        int high = *max_element(nums.begin(),nums.end()) - *min_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(helper(nums,p,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};