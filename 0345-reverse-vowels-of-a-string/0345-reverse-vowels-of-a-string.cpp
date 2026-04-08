class Solution {
public:

    bool isVowel(char c) {
    c = std::tolower(c);
    string vowels = "aeiou";
    return vowels.find(c) != string::npos;
}
    string reverseVowels(string s) {

        int i = 0;
        int j = s.length() - 1;

        while(i<j)
        {
            while(i<j && !isVowel(s[i])) i++;
            while(i<j && !isVowel(s[j])) j--;
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch ;
            i++;
            j--;
        }

        return s;
        
    }
};