class Solution {
public:
    bool check(int n, int maxSum, int index, int mid) {
        int leftLength = index;
        int rightLength = n - index - 1;
        long long leftSum = getSlopeSum(leftLength, mid);
        long long rightSum = getSlopeSum(rightLength, mid);
        long long totalSum = leftSum + mid + rightSum;

        return totalSum <= maxSum;
    }
    long long getSlopeSum(int length, int mid) {
        long long val = mid - 1;
        long long fullTriangle = val * (val + 1) / 2;
        if (length < val) {
            // Case 1: The slope hits the boundary before reaching 0.
            // It gets chopped off. Your exact logic applies here!
            long long choppedOff = (val - length) * (val - length + 1) / 2;
            return fullTriangle - choppedOff;
        } else {
            // Case 2: The slope reaches 0 naturally.
            // Because we used the "maxSum - n" trick, the remaining spaces are
            // just 0s.
            return fullTriangle + length - mid + 1;
        }
    }
    int maxValue(int n, int index, int maxSum) {
        int low = 1;
        int high = maxSum;

        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (check(n, maxSum,index, mid))
                low = mid;
            else
                high = mid-1;
        }
        return low;
    }
};

// nums[mid] = max.
// smallest sum = 1 to mid => Left side Sum
// right side after mid length = n-index