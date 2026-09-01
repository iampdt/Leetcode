class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int m = nums1.size(), n = nums2.size();
        int halfLen = (m + n + 1) / 2;
        int searchLow = 0, searchHigh = m;
        while (searchLow <= searchHigh) {
            int partA = searchLow + (searchHigh - searchLow) / 2;
            int partB = halfLen - partA;
            int maxLeftA = (partA == 0) ? INT_MIN : nums1[partA - 1];
            int minRightA = (partA == m) ? INT_MAX : nums1[partA];
            int maxLeftB = (partB == 0) ? INT_MIN : nums2[partB - 1];
            int minRightB = (partB == n) ? INT_MAX : nums2[partB];
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 1)
                    return max(maxLeftA, maxLeftB);
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            }
            if (maxLeftA > minRightB) searchHigh = partA - 1;
            else searchLow = partA + 1;
        }
        return 0.0;
    }
};