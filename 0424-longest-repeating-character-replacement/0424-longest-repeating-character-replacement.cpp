class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> mp;
        int i=0;
        int max_len = 0;
        int ans = -1;
        for(int j=0;j<s.length();j++)
        {
            mp[s[j]]++;
            if(max_len < mp[s[j]])
            {
             max_len = max(max_len,mp[s[j]]);
            }
            while(j-i+1 - max_len > k)
            {
                mp[s[i]]--;
                i++;
            }
           ans = max(ans,j-i+1);
            

        }
        return ans;
    }
};