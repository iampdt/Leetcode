class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> ans;
        int count = 0;
        int i = 0;
        int j = n;
        for(int k=0;k<s.length();k++)
        {
            if(s[k] == 'I') {ans.push_back(i++); count++;}
            else ans.push_back(j--);
             
        }
        if(count > n/2) ans.push_back(j);
        else ans.push_back(i);
        return ans;
        
    }
};