class Solution {
public:
    bool helper(int n ,vector<int>&nums,int mid)
    {
       int cnt = 0;
       for(int i=0;i<nums.size();i++)
       {
         if(nums[i]%mid == 0) cnt+= nums[i]/mid;
         else cnt+= nums[i]/mid + 1;
       }
       return cnt <= n;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        
        int low = 1;
        int high = 1e9;

        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(helper(n,nums,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};