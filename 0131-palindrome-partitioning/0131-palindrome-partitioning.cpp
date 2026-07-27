class Solution {
public:
    vector<vector<bool>> isPal;
    vector<vector<string>> result;
    vector<string> cur;
    string s;
    void backtrack(int i) {
        if (i == (int)s.size()) { result.push_back(cur); return; }
        for (int j = i; j < (int)s.size(); j++) {
            if (isPal[i][j]) {
                cur.push_back(s.substr(i, j - i + 1));
                backtrack(j + 1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s_) {
        s = s_;
        int n = s.size();
        isPal.assign(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPal[i + 1][j - 1])) isPal[i][j] = true;
            }
        }
        backtrack(0);
        return result;
    }
};