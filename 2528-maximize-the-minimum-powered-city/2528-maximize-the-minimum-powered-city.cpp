class Solution {
public:
    bool check(vector<long long>& prefix,int r,int k, long long mid)
    {
        long long rem = k;
        int n = prefix.size();
        vector<long long> running_sum(n,0);
        long long added_power = 0;
        for(int i=0;i<prefix.size();i++)
        {
            if(i-r-1>=0)
            {
                added_power -= running_sum[i-r-1];
            }
            int left = i-r-1;
            int right = min(n-1,i+r);

            long long val = left>=0 ? prefix[right] - prefix[left] : prefix[right];
            long long tot_val = val + added_power;
            if(tot_val < mid)
            {
            long long req = mid - tot_val;
            if(req > rem) return false;
            else 
            {
                rem-=req;
                int build_pos = min(n-1,i+r);
                added_power+=req;
                running_sum[build_pos]+=req;
            }
            }
        }
        return true;
        
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        // prefix sum to store the total powers
        int n = stations.size();
        vector<long long> prefix(n,0);
        prefix[0] = stations[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + 1LL*stations[i];
        }
        long long low = 0;
        long long high = prefix[n-1] + k;

        while(low < high)
        {
            long long mid = low + (high - low + 1)/2;
            if(check(prefix,r,k,mid)) low = mid;
            else high = mid - 1;
        }
        return low;
        
    }
};
// 1 3 7 12 12 
// prefix[i + r] - prefix[i]  
// r - range of station to provide power
// k - power stations in multiple cites