class Solution {
public:
    void solve(int idx,vector<string> temp,vector<vector<string>> &res,string &s,set<string>&st)
    {
        if(idx == s.size()) 
        {
            res.push_back(temp);
            return;
        }

        for(int i = idx;i<s.length();i++)
        {
            if(st.find(s.substr(idx,i-idx+1)) != st.end())
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,temp,res,s,st);
                temp.pop_back();
            }
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        set<string> st;
        int n = s.length();
        
        for(int i=0;i<wordDict.size();i++)
        {
            st.insert(wordDict[i]);
        }
        vector<vector<string>> res;
        vector<string> temp;
        vector<string> ans;
        solve(0,temp,res,s,st);
        for(auto it: res)
        {
            string curr;
            for(auto i:it) {curr+=i; curr+=" ";}
            curr.pop_back();
            ans.push_back(curr);
            cout<<endl;
        }
        return ans;
    }

};