class Solution {
public:
    bool helper(vector<int>&ranks,int cars,long long mid)
    {
        long long cnt = 0;
        for(int i=0;i<ranks.size();i++)
        {
            cnt += sqrt(mid/ranks[i]);
            if(cnt >= cars) return true;
        }

        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        
        long long low = 0;
        long long high = 1e18;

        while(low < high)
        {
            long long mid = low + (high-low)/2;
            if(helper(ranks,cars,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};