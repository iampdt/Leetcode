class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        // queries iterate kro
        // prefix or storing of data for O(1) retrival

        vector<int> closest(nums.size(), -1);
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                closest[i] = 1; 
            } else if (i == nums.size() - 1) {
                closest[i] = nums.size() - 2; 
            } else {
                int leftDiff = abs(nums[i] - nums[i - 1]);
                int rightDiff = abs(nums[i] - nums[i + 1]);

                if (leftDiff <= rightDiff)
                    closest[i] = i - 1;
                else
                    closest[i] = i + 1;
            }
        }
        vector<int> prefix(nums.size(),0);
        vector<int> suffix(nums.size(),0);
        prefix[0] = 0;

        for(int i=1;i<nums.size();i++)
        {
            if(closest[i-1] == i) prefix[i] = prefix[i-1] + 1;
            else prefix[i] = 1LL*(prefix[i-1] + abs(nums[i]-nums[i-1]));
        }
        suffix[nums.size()-1] = 0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(closest[i+1] == i) suffix[i] = suffix[i+1] + 1;
            else suffix[i] = 1LL*(suffix[i+1] + abs(nums[i+1] - nums[i]));
        }
        for(auto it:prefix) cout<<it<<" ";
        cout<<endl;
        for(auto it:suffix) cout<<it<<" ";
        for(int i=0;i<queries.size();i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            if(l == r) ans.push_back(0);
            else if(l<r)
            {
                ans.push_back(prefix[r]-prefix[l]);
            }
            else 
            {
                ans.push_back(suffix[r] - suffix[l]);
            }
        }
        return ans;
    }
};