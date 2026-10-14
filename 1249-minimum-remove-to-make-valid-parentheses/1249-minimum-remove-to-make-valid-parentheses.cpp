class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string ans="";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if(s[i]==')') {
                if (st.empty()) {
                    s[i]='0';
                } else {
                    st.pop();
                }
            }
        }
        if (!st.empty()) {
            while (!st.empty()) {
                s[st.top()]='0';
                st.pop();
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                ans+=s[i];
            }
        }
        return ans;
    }
};