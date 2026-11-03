class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> s;
        s.insert(wordList.begin(),wordList.end());

        queue<pair<int,string>> q;
        q.push({1,beginWord});
        s.erase(beginWord);

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            string str = it.second;
            if(str == endWord) return steps;
          
          for(int i=0;i<str.length();i++)
          {
            string org = str;
            for(char ch = 'a'; ch<='z';ch++)
            {
                str[i] = ch;
                if(s.find(str)!=s.end())
                {
                    s.erase(str);
                    q.push({steps+1,str});
                }
            }
            str = org; 
          }
        }

        return 0;
    }
};


// bfs set word search 
// set wordList ke words daal do 
// start word se shru kro than go on seaching for each word and trying to pick the next one 