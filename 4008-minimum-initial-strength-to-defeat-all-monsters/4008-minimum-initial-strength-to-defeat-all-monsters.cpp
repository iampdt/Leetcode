class Solution {
public:
    bool isPossible(vector<int>& monsters,vector<long long>& bonusPower, long long power)
    {
        for(int i=0;i<monsters.size();i++)
        {
            if(power + bonusPower[i] >= 1LL*monsters[i])
            {
                power -= monsters[i];
                if(power < 0) power = 0;
            }
            else return false;
        }

        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        
        int n = monsters.size();
        vector<long long> bonusPower(n,0);
        vector<long long> temp(n,0);

        for(int i=0;i<boosts.size();i++)
        {
            int ini = boosts[i][0];
            int end = boosts[i][1];
            long long val = boosts[i][2];

            temp[ini]+= val;
            if(end+1<n) temp[end+1]-= val;
        }
        bonusPower[0] = temp[0];
        for(int i=1;i<n;i++)
        {
            bonusPower[i] = temp[i] + bonusPower[i-1];
        }

       long long low = 0;
       long long high = accumulate(monsters.begin(),monsters.end(),0LL);

       while(low < high)
       {
         long long mid = low + (high - low)/2;
         if(isPossible(monsters,bonusPower,mid)) high = mid;
         else low = mid + 1;
       }

       return low;

    }
};