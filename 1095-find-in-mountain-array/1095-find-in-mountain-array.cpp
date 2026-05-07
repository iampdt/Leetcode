/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &nums) {
        
        int n = nums.length();
        int low = 0;
        int high = n - 1;

        while(low < high)
        {
            int mid = low + (high - low)/2;
                if(nums.get(mid) > nums.get(mid + 1)) high = mid;
                else low = mid + 1;

        }
        cout<<low;
        int p1 = low;
        int p2 = low;

        int l1 = 0;
        int h2 = n - 1;

        while(l1 < p1)
        {
            int mid = l1 + (p1 - l1)/2;
            if(nums.get(mid) == target) return mid;
            else if(nums.get(mid) > target) p1 = mid;
            else l1 = mid + 1;
        }
        if(nums.get(l1) == target) return l1;
        while(p2 < h2)
        {
            int mid = p2 + (h2 - p2)/2;
            if(nums.get(mid) == target) return mid;
            else if(nums.get(mid) < target) h2 = mid;
            else p2 = mid + 1;
        }
        if(nums.get(p2) == target) return p2;

        return -1;

    }
};