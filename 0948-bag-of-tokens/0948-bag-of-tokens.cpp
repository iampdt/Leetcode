class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(),tokens.end());
        int max_score = 0;
        int ans = 0;

        int i = 0;
        int j = tokens.size() - 1;

        if(i == j) return power >= tokens[i] ? 1 : 0;

        while(i<j)
        {
           while(i<tokens.size() && power >= tokens[i]) 
           {
               max_score += 1;
               power-=tokens[i];
               ans = max(ans,max_score);
               i++;
           }
           if(max_score > 0) 
           {
             max_score -=1;
             power+=tokens[j];
             j--;
           }
           if(max_score == 0 && power < tokens[i]) break;
        }

        return ans;

        
    }
};