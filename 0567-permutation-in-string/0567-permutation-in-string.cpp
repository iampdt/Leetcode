class Solution {
public:
    bool checkInclusion(string p, string s) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<p.length();i++) mp1[p[i]]++;
   
        int i=0;
        for(int j=0;j<s.length();j++)
        {
            mp2[s[j]]++;
            while(j-i+1>p.length())
            {
                mp2[s[i]]--;
                if(mp2[s[i]]==0) mp2.erase(s[i]);
                i++;
            }
            if(j-i+1==p.length() && mp1==mp2) return true;
        } 

        return false;
    }
};