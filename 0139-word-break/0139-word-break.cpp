class Solution {
public:
    bool solve(int index, string &s,vector<string>& wordDict,set<string>& st,vector<int>&dp)
    {
       if(index >= s.length()) return true;
       if(dp[index] != -1) return dp[index];
       for(int i = index;i<s.length();i++)
       {
         if(st.find(s.substr(index,i-index+1)) != st.end() && solve(i+1,s,wordDict,st,dp)) return dp[index] = true;
       }
       return dp[index] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int> dp(s.length()+1,-1);
        for(auto it: wordDict) st.insert(it);
        return solve(0,s,wordDict,st,dp);

    }
};