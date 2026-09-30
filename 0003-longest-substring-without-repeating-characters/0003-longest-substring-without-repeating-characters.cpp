class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans = 0;

        int i = 0;
        for(int j=0;j<s.length();j++)
        {
            mp[s[j]]++;
            while(j-i+1 > mp.size())
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            ans = max(ans,j-i+1);
        }

        return ans;

    }
};