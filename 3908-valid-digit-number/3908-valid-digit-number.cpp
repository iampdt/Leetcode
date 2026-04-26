class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        cout<<s;
        if(s[0] == x + '0') return false;
        for(int i=1;i<s.length();i++) { if(s[i] == x + '0') return true;}
        return false;
        
    }
};