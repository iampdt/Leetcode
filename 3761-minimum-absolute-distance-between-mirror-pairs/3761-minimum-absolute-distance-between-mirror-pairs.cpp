class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        
        unordered_map<int,vector<int>> mp;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        } 

        for(int i=0;i<nums.size();i++)
        {
             string a = to_string(nums[i]);
             reverse(a.begin(),a.end());
             int b = stoi(a);
            //  cout<<b<<" ";

             if(mp.find(b) != mp.end())
             {
                cout<<i<<" ";
                int idx = upper_bound(mp[b].begin(),mp[b].end(),i)-mp[b].begin();
                if(idx < mp[b].size()) ans = min(ans,mp[b][idx]-i);


             }
        }

        return ans >=INT_MAX ? -1 : ans;
        
    }
};