class Solution {
public:
    bool checkInclusion(string p, string s) {
        unordered_map<char,int> mp1;
        // unordered_map<char,int> mp2;
        for(int i=0;i<p.length();i++) mp1[p[i]]++;
   
        int i=0;
        for(int j=0;j<s.length();j++)
        {
            mp1[s[j]]--;
           if(mp1[s[j]] == 0) mp1.erase(s[j]);
            while(j-i+1>p.length())
            {
              mp1[s[i]]++;
              if(mp1[s[i]] == 0) mp1.erase(s[i]);
              i++;
            }
            if(mp1.size() == 0) return true;
        } 

        return false;
    }
};