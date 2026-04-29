class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {

        int ans = INT_MIN;
        int i=0;
        int duplicates = 0;
        if(s.length() == 1) return 1;
        for(int j=1;j<s.length();j++)
        {
            if(s[j] == s[j-1]) duplicates++;
            while(duplicates > 1)
            {
               if(s[i] == s[i+1]) duplicates--;
                i++;
            }
            ans = max(ans,j-i+1);
        }

        return ans == INT_MIN ? 0 : ans;
        
    }
};