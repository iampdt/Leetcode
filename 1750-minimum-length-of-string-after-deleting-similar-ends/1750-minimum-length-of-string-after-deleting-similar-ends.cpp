class Solution {
public:
    int minimumLength(string s) {

        int i =0;
        int j = s.length()-1;
        char ch = 'd';

        while(i<j)
        {
           if(s[i] == s[j]) {ch = s[i]; i++; j--;}
           else if(s[i] == ch) i++;
           else if(s[j] == ch) j--;
           else break;

        }
        cout<<i<<" "<<j<<" "<<s.length();
        if(ch == s[i]) i++;
        if(ch == s[j]) j--;
        return j<i ? 0 : j-i+1;
        }
};