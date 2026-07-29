class Solution {
public:
    bool helper(string s,unordered_set<string>& dict) {
        // unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       sort(words.begin(), words.end(), [](const string& a, const string& b) {
    return a.size() < b.size();
});
        unordered_set<string> dict;
       vector<string> ans;
       for(int i=0;i<words.size();i++)
       {
         string str = words[i];
         if(helper(str,dict)) ans.push_back(str);
         dict.insert(str);
       }
      

      return ans;

    }
};