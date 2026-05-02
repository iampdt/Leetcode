class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        if(n<=1) return ans;
        vector<int> primes(n+1,1);

        primes[0] = primes[1] = 0;

        for(int i=2;i*i<=n;i++)
        {
            if(primes[i])
            {
             for(int j = i*i;j<=n;j+=i)
             {
                primes[j] = 0;
             }
            }
        }

        for(int i=0;i<=n/2;i++)
        {
            vector<int> temp;
            if(primes[i] == 1 && primes[n-i] == 1)  { temp.push_back(i); temp.push_back(n-i);}
            if(temp.size() > 0) ans.push_back(temp);
        }
        return ans;
    }
};