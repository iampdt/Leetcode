class Solution {
public:
    bool isSorted(vector<int>&nums)
    {
        for(int i=0;i<nums.size()-1;i++) 
        {
            if(nums[i] > nums[i+1]) return false; 
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        // messed up array
        int n=nums.size();
        if(isSorted(nums)) return 0;
        bool flag = true;
        for(int i=1;i<nums.size();i++)
        {
            if(abs(nums[i]-nums[i-1]) == 1) continue;
            else 
            {
                if(abs(nums[i] - nums[i-1]) != n-1) return -1;
            }

        }

        int cnt = 0;
        int idx = 0;
        int ans = 0;
        // increasing
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == 0) idx = i;
            if(nums[i]-nums[i-1] == 1) continue;
            else 
            {
                cnt++;
            }
        }
        if(cnt == 1) 
        {
            ans = min(idx, 2 + (n-idx)%n);

        } 
        else
        {
            ans =  min(1+(idx+1)%n,n-idx);
        }
        return ans;

    }
};

// increasing array 
// decreasing array 
// messed up array