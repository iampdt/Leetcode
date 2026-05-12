class Solution {
public:
    bool check(vector<int>& candies, long long k,long long mid)
    {
        long long cnt = 0;
        for(int i = 0;i<candies.size();i++)
        {
            if(candies[i] >= mid) cnt+=1LL*(candies[i]/mid);
        }
       return cnt >= k;
     }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int i=0;i<candies.size();i++) sum += 1LL*candies[i];
        if(sum < k) return 0;

        long long low = 1;
        long long high = sum / k;
        while(low < high)
        {
            long long mid = low + (high - low + 1)/2;
            if(check(candies,k,mid)) low = mid;
            else high = mid - 1;
        }
        return (int)low;
    }
};