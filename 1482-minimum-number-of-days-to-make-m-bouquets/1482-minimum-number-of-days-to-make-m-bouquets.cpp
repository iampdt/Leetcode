class Solution {
public:
    bool helper(vector<int>&nums,int m, int k, int mid)
    {
       int cnt = 0;
       int ans = 0;
       for(int i=0;i<nums.size();i++)
       {
         if(nums[i] <= mid) cnt++;
         else cnt = 0;
         if(cnt == k) 
         {
           ans++;
           cnt=0;
         }
       }
       return ans >= m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        if(1LL*m*k > nums.size()) return -1;
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());

        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(helper(nums,m,k,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
        
    }
};