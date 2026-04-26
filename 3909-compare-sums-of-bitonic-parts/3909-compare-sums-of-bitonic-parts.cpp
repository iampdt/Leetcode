class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int idx = -1;
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) idx = i;
        }
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i=0;i<=idx;i++) sum1+=nums[i];
        for(int i=idx;i<nums.size();i++) sum2+=nums[i]; 
         cout<<idx<<" "<<sum1<<" "<<sum2<<endl;
        if(sum1 == sum2) return -1;
        else if(sum1 > sum2) return 0;
        return 1;
    }
};