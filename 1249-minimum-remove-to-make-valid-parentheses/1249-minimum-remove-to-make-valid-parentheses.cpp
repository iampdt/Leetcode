class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<int> stk;
        unordered_map<int,int> mp;
        for(int i=0;i<s.length();i++)
        {
           if(s[i] == '(') 
           {
             stk.push(i);
           }
           else if(s[i] == ')' && !stk.empty())
           {
                mp[stk.top()]++;
                stk.pop();
                mp[i]++;
           }
           
        }

        for(int i=0;i<s.length();i++)
        {
            if(s[i] != '(' && s[i] != ')') ans+=s[i];
            else if((s[i] == '(' || s[i] == ')') && mp.find(i) != mp.end()) { ans+=s[i]; mp.erase(i);}

        }

        
     return ans;

    }
};