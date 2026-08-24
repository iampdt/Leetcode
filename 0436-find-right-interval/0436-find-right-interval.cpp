class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<int> nums(n,0),ans(n,-1);
        unordered_map<int,int> mp;

        for(int i=0;i<intervals.size();i++)
        {
            int start = intervals[i][0];
            nums[i] = start;
            mp[start] = i;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<intervals.size();i++)
        {
            int end = intervals[i][1];
            int low = 0;
            int high = n-1;
            while(low < high)
            {
                int mid = low + (high - low)/2;
                if(nums[mid] < end) low = mid + 1;
                else high = mid;
             }
            cout<<low;
            if(low < n && nums[low] >= end) ans[i]=mp[nums[low]];
            
        }
        return ans;

    }
};