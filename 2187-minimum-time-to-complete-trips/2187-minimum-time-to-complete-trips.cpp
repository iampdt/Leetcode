class Solution {
public: 
    bool helper(vector<int>&time,int totalTrips,long long mid)
    {
        long long cnt = 0;
        for(int i=0;i<time.size();i++)
        {
            cnt+=1LL*(mid/time[i]);
            if(cnt>=totalTrips) break;
        }
        return cnt >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long low = 1;
        long long high = 1e18;

        while(low < high)
        {
            long long mid = low + (high-low)/2;
            if(helper(time,totalTrips,mid)) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};