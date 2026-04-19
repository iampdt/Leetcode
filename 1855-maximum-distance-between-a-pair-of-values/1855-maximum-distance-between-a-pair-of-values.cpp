class Solution {
public:
    int solve(vector<int>&nums2,int val)
    {
        int low = 0;
        int high = nums2.size()-1;
        int ans = -1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums2[mid] >= val)
            {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        //Binary Search Approach
        int ans =INT_MIN;
        for(int i=0;i<nums1.size();i++)
        {
           auto idx = solve(nums2,nums1[i]);
           if(idx>=i) ans = max(ans,(idx-i));
        }
            return ans == INT_MIN ? 0 : ans;
        
    }
};