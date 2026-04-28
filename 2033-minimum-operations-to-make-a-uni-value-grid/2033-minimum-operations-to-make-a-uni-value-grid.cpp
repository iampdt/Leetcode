class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> nums;
        int ans = 0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(),nums.end());
        int n = nums.size();
        int target = nums[n/2];

        for(int i=0;i<n;i++)
        {
            if(abs(target-nums[i])%x == 0) ans+=abs(target-nums[i])/x;
            else return -1;
        }
        return ans;
        
    }
};