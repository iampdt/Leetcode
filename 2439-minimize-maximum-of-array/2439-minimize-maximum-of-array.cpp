class Solution {
public:
    bool helper(vector<long long>&prefix, int mid)
    {
        int maxi = 0;
        for(int i=0;i<prefix.size();i++)
        {
           int s = ceil((double)prefix[i]/(double)(i+1));
           maxi = max(maxi,s);
           if(maxi > mid) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {

        int low = 0;
        int n = nums.size();
        int high = *max_element(nums.begin(),nums.end());
        vector<long long> prefix(n+1,0);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i] = 1LL*prefix[i-1] + 1LL*nums[i];
        }
        
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(helper(prefix,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};