class Solution {
public:
    int longestBalanced(string s) {
        int total_ones = 0;
        int total_zeroes = 0;
        unordered_map<int,vector<int>> mp;
        mp[0].push_back(-1);
        int running_sum=0;
        int ans = 0;
        for(int i=0;i<s.length();i++){if(s[i] == '1') total_ones++; else total_zeroes++;}
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '0') running_sum-=1;
            else running_sum+=1;
            if(mp.count(running_sum)) ans = max(ans,i-mp[running_sum][0]);
            if(mp.count(running_sum - 2))
            {
                int min_len = i - 2 * total_zeroes - 1;
                auto it = lower_bound(mp[running_sum - 2].begin(),mp[running_sum - 2].end(),min_len);
                if(it != mp[running_sum -2].end()) ans = max(ans,i-*it);
            }
            if(mp.count(running_sum + 2)) 
            {
                int min_len = i - 2 * total_ones - 1;
                auto it = lower_bound(mp[running_sum + 2].begin(),mp[running_sum + 2].end(),min_len);
                if(it != mp[running_sum + 2].end()) ans = max(ans,i-*it);
            }
            mp[running_sum].push_back(i);

        }

        return ans;
    }
};