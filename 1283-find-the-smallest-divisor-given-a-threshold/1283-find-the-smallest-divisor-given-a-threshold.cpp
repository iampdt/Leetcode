class Solution {
public:
    bool helper(vector<int>&nums,int threshold,int mid)
    {
        double sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum += ceil((double)nums[i]/(double)mid);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = 1e9;

        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(helper(nums,threshold,mid)) high = mid;
            else low = mid +1;
        }
        return low;
    }
};