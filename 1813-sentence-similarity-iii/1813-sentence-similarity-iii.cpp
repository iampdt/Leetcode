class Solution {
public:
    bool solve(vector<string>&v1, vector<string>&v2)
    {
        if (v1.size() > v2.size()) return false;
        int i = 0;
        int j = v2.size() - 1;

        for(int k =0;k<v1.size();k++) {if(v1[k] == v2[i]) i++; else break;}
        for(int k =v1.size()-1;k>=0;k--) {if(v1[k] == v2[j]) j--; else break;}
        return (i + (v2.size() - 1 - j)) >= v1.size();

    }
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);
        vector<string> v1;
        vector<string> v2;

        string word;
        while(ss1 >> word) v1.push_back(word);
        while(ss2 >> word) v2.push_back(word);

        return solve(v1,v2) || solve(v2,v1);
    }
};