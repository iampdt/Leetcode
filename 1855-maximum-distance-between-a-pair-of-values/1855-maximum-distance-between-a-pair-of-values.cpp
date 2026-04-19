class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        // Two pointer
        int i = 0;
        int j = nums2.size() - 1;
        int ans = 0;

        while(i<nums1.size() && j>=0)
        {
           if(i>j) break;
           if(nums1[i] <= nums2[j] && i<=j) {ans = max(ans,j-i); break;}
           j--;
           
        }
         i = 0;
         j = nums2.size() - 1;

         while(i<nums1.size() && j>=0)
        {
           if(i>j) break;
           if(nums1[i] <= nums2[j] && i<=j) {ans = max(ans,j-i); break;}
           i++;
           
        }

        return ans;


    }
};