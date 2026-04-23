class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
       
        int n = nums.size();
        vector<long long> ans(n,0);
        unordered_map<long long,vector<long long>> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
         for(auto it:mp)
         {
            cout<<it.first<<" ";
            for(auto iit:it.second)
            {
                cout<<iit<<" ";
            }
             cout<<endl;
         }
         cout<<endl;
        
        for (auto& it : mp) {
            vector<long long>& indices = it.second;
            long long k = indices.size();
            
            long long total_sum = 0;
            for (long long idx : indices) {
                total_sum += idx;
            }
            long long left_sum = 0;
            for (long long m = 0; m < k; m++) {
                long long current_index = indices[m];
                long long right_sum = total_sum - left_sum - current_index;
                
                long long left_part = (m * current_index) - left_sum;
                long long right_part = right_sum - ((k - 1 - m) * current_index);
                
                ans[current_index] = left_part + right_part;
                
                left_sum += current_index;
            }
        }
        
        return ans;
    }
};