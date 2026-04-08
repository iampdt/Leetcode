class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {


        const int mod = 1e9 + 7;
        int ans = 0;
        for(int i=0;i<q.size();i++)
        {
            int start = q[i][0];
            int end = q[i][1];
            int inc = q[i][2];
            int val = q[i][3];

            for(int j = start; j<=end && j<nums.size();j+=inc)
            {
                nums[j] = int((1LL*nums[j] * val)%mod);
            }
        }

        for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";

        for(int i=0;i<nums.size();i++) ans ^= nums[i];

        return ans;


        
    }
};