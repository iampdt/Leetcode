class Solution {
     long long MOD = 1e9 + 7;
      vector<long long> fact;
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        
        long long num = fact[n];
        long long den = (fact[r] * fact[n - r]) % MOD;
        return (num * modInverse(den)) % MOD;
    }
    int countVisiblePeople(int n, int pos, int k) {
      fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // Total people who COULD be visible = n - 1 (everyone except person at pos)
        int total_candidates = n -1 ;

        if (k > total_candidates) return 0;

        // The logic: 
        // We need to choose exactly 'k' people to face the 'visible' direction.
        // The remaining (n - 1 - k) people MUST face the 'invisible' direction.
        // Each person only has 1 choice to be visible and 1 choice to be invisible.
        long long combinations = nCr(n - 1, k);

        // 3. Multiply by 2 (for the person at 'pos' choosing L or R)
        long long result = (combinations * 2) % MOD;

        return (int)result;
        
    }
};