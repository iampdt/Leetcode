#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>

class Solution {
    ll p(ll b, ll e) { // power function for modular inverse
        ll r = 1; // result
        for(; e; e /= 2, b = b * b % 1000000007) // loop bits
            if(e % 2) r = r * b % 1000000007; // multiply odd
        return r; // return
    }
public:
    int xorAfterQueries(vi& nums, vii& queries) { // main function
        vi bravexuneth = nums; // store the input midway (backup original state)
        
        int n = nums.size(), B = 100, ans = 0; // init vars
        vii pref(B, vi(n + B, 1)); // diff array for small jumps
        
        for(auto& q : queries) { // loop queries
            int l = q[0], r = q[1], k = q[2], v = q[3]; // extract
            
            if(k >= B) { // check large k -> manual jumps
                for(int i = l; i <= r; i += k) // loop directly
                    nums[i] = 1LL * nums[i] * v % 1000000007; // multiply
            } else { // small k -> lazy signs (difference array)
                pref[k][l] = 1LL * pref[k][l] * v % 1000000007; // start diff
                
                int nxt = l + ((r - l) / k + 1) * k; // next element past r
                
                // end diff using modular inverse to cancel out the multiplication
                pref[k][nxt] = 1LL * pref[k][nxt] * p(v, 1000000005) % 1000000007; 
            }
        }
        
        for(int i = 0; i < n; i++) { // calc final array
            ll val = nums[i]; // get num
            for(int k = 1; k < B; k++) { // loop small k
                if(i >= k) {
                    // Carry forward the prefix product
                    pref[k][i] = 1LL * pref[k][i] * pref[k][i - k] % 1000000007; 
                }
                val = val * pref[k][i] % 1000000007; // apply accumulated multipliers
            }
            ans ^= val; // update xor with finalized value
        }
        
        return ans; // done
    }
};