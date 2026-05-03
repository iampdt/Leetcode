class Solution {
public:
    int sumOfPrimesInRange(int n) {

        string s = to_string(n);
        reverse(s.begin(),s.end());
        int a = stoi(s);

        int low = min(a,n);
        int high = max(a,n);

        vector<int> primes(high+1,1);
        primes[0] = primes[1] = 0;
        for(int i=2;i*i<=high;i++)
        {
            if(primes[i])
            {
            for(int j=i*i;j<=high;j+=i)
            {
               primes[j] = 0;   
            }
            }
        }
        int sum = 0;
        for(int i=low;i<=high;i++)
        {
            if(primes[i]) sum+=i;
        }

        return sum;
        
    }
};