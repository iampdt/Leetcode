class Solution {
public:
    bool helper(string s, string t)
    {
        int cnt = 0;
        int i =0;
        int j =0;
        while(i<s.length() && j<t.length())
        {
            if(s[i] == t[j]) { i++; j++;}
            else if(s[i] != t[j] && cnt == 0) { cnt++; j++;}
            else return false;
        }
        if(abs(j-i) > 1) return false;
        return true;
    }
    int longestStrChain(vector<string>& words) {

        int n = words.size();    
        vector<int> dp(n+1,1);
        int len = 1;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
    });
        
        for(int i=0;i<n;i++)
        {
            for(int prev = 0;prev < i;prev++)
            {
               if(words[i].length() == words[prev].length()+1 && helper(words[prev],words[i])) dp[i] = max(dp[i],1+dp[prev]);
               
            }
            len = max(len,dp[i]);
        }
        return len;

    }
};

// Previous word store 