class Solution {
public:
    int solve(char ci,char cj,int k,string word,unordered_map<char,pair<int,int>> &mp,vector<vector<vector<int>>>&dp)
    {
        if(k==word.length()) return 0;
        if(dp[ci-'A'][cj-'A'][k] != -1) return dp[ci-'A'][cj-'A'][k];

        //index of ci 
        auto iti = mp[ci];
        int xi = iti.first;
        int yi = iti.second;

        //index of cj
        auto itj = mp[cj];
        int xj = itj.first;
        int yj = itj.second;

        // index of word[k]
        auto itk = mp[word[k]];
        int xk = itk.first;
        int yk = itk.second;

        int diff1 = abs(xi - xk) + abs(yi -yk);
        int diff2 = abs(xj - xk) + abs(yj - yk);

        int choice_one = solve(word[k],cj,k+1,word,mp,dp) + diff1;
        int choice_two = solve(ci,word[k],k+1,word,mp,dp) + diff2;

        return dp[ci - 'A'][cj - 'A'][k] = min(choice_one,choice_two);

    }
    int minimumDistance(string word) {

        unordered_map<char,pair<int,int>> mp;
        char ch = 'A';
        int i=0;
        
        while(ch<='Z')
        {
            for(;i<4;i++)
            {
                for(int j=0;j<6;j++)
                {
                    mp[ch]={i,j};
                    ch++;
                }
                
            }
            mp[ch]={4,0};
            ch++;
            mp[ch]={4,1};
            break;

        }
        int ans = INT_MAX;
        vector<vector<vector<int>>> dp(26,vector<vector<int>>(26,vector<int>(word.length()+1,-1)));
        for(char ci ='A';ci<='Z';ci++)
        {
            for(char cj='A';cj<='Z';cj++)
            {
                ans = min(ans,solve(ci,cj,0,word,mp,dp));
            }
        }
        return ans;
    }
};