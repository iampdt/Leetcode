class Solution {
public:
    int kthFactor(int n, int k) {
        
        vector<int> small;
        vector<int> large;
        for(int i=1;(long long)i*i<=n;i++)
        {
                if(n%i==0) 
                {
                  small.push_back(i);
                 if(n/i != i) large.push_back(n/i);
                }
        }
        reverse(large.begin(),large.end());
        for(auto it:large) small.push_back(it);

        for(auto it: small) cout<<it<<" ";
        return k > small.size() ? -1 : small[k-1];
    }
};