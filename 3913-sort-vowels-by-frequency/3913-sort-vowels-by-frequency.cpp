class Solution {
public:
    bool is_vowel(char c)
    {
        return (c == 'a' || c == 'e' || c== 'i' || c == 'o' || c=='u');
    }
    string sortVowels(string s) {
        

        unordered_map<char, int> freq;
    unordered_map<char, int> first_occ;
    
    // 1. Map frequencies and track first occurrences
    for (int i = 0; i < s.length(); i++) {
        if (is_vowel(s[i])) {
            freq[s[i]]++;
            if (first_occ.find(s[i]) == first_occ.end()) {
                first_occ[s[i]] = i;
            }
        }
    }

    priority_queue<pair<int, pair<int, char>>> pq;
    for (auto const& [ch, count] : freq) {
        pq.push({count, {-first_occ[ch], ch}});
    }

     string sortedVowels = "";
    while (!pq.empty()) {
        auto top = pq.top();
        int count = top.first;
        char ch = top.second.second;
        pq.pop();
        sortedVowels.append(count, ch);
    }
    cout<<sortedVowels;
    int j =0;
    for(int i=0;i<s.length();i++)
    {
        if(is_vowel(s[i])) s[i] = sortedVowels[j++];
    }
    return s;
    }
};