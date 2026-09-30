class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        unordered_map<char,int> mp2;
        int st=-1;
        for(int i=0;i<t.length();i++) mp[t[i]]++; 
        unordered_map<char,int> original_mp = mp;
        int ans = INT_MAX;
        int i=0;
        for(int j=0;j<s.length();j++)
        {
            if(mp.count(s[j]) > 0)
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0) mp.erase(s[j]);
            }
            else if (original_mp.count(s[j]) > 0) mp2[s[j]]++;
            while(mp.size() == 0)
            {
                if(ans > j-i+1)
                {
                    st = i;
                    ans = j-i+1;
                    // str = s.substr(i,j-i+1);
                }
                if(original_mp.count(s[i]) > 0) 
                {
                    if(mp2[s[i]] > 0) mp2[s[i]]--;
                    else mp[s[i]]++;
                }
                i++;
            }  
        }
        if(st == -1) return "";
        return s.substr(st, ans);;
    }
};