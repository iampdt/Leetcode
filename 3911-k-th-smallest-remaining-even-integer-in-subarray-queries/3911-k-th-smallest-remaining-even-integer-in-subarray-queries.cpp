class Solution {
public:
    int solve(int left, int right,int k,vector<int>&nums,vector<int>&prefix)
    {
        int diff = 0;
        int original_left = left;
        while(left<=right)
        {
            int mid = left + (right - left)/2;
             int count = original_left == 0 ? prefix[mid] : prefix[mid] - prefix[original_left-1];
           if ((nums[mid] / 2) - count < k)
             {
                diff = count;
                left = mid + 1;
             }
             else right = mid - 1;

        }

        return diff;
    }
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        

        vector<int> ans(queries.size(),0);
        vector<int> prefix(nums.size(),0);
        if(nums[0] % 2 ==0) prefix[0] = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]%2==0) prefix[i] = prefix[i-1] + 1;
            else prefix[i] = prefix[i-1];
        }
        for(auto it: prefix) cout<<it<<" ";
        cout<<endl;
        for(int i=0;i<queries.size();i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int k = queries[i][2];

            // binary search on nums 
            int diff = solve(left,right,k,nums,prefix);
            ans[i] = (k+diff)*2;
            cout<<diff<<endl;

        }

        return ans;
    }
};