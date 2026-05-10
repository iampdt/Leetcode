class Solution {
public:
    bool isPossible(vector<int>&nums,int k,int mid)
    {
        int sum = 0;
        int cnt = 1;
        for(int i=0;i<nums.size();i++)
        {
            sum+= nums[i];
            if(sum > mid)
            {
                cnt++;
                sum = nums[i];
            } 
        
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0)+1;

        while(low < high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(nums,k,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};