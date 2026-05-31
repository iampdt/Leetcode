class Solution {
public:
    int passwordStrength(string s) {
        int sum = 0;
        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i])) 
            {
                if(islower(s[i]) && !mp.count(s[i]))
                {
                    sum+=1;
                    mp[s[i]]++;
    
                }
                else if(isupper(s[i]) && !mp.count(s[i]))
                {
                    sum+=2;
                   mp[s[i]]++;
                }
                 
            }
            else if(isdigit(s[i]) && !mp.count(s[i]))
            {
                sum+=3;
                mp[s[i]]++;
            }
            else
            {
                if(!mp.count(s[i]))
                {
                    sum+=5;
                    mp[s[i]]++;
                }
            }
        }
        return sum;
    }
};