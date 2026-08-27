class Solution {
public:
    bool isPossible(vector<int>& chargeTimes, vector<int>& runningCosts,int mid, long long budget)
    {
        if(mid == 0) return true;
        long long sum=0;
        long long maxi = -1;

        int i = 0;
        deque<int> dq;

        for(int j=0;j<runningCosts.size();j++)
        {
            sum+=runningCosts[j];
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[j]) dq.pop_back();
            dq.push_back(j);
            while(j-i+1 > mid) 
            {if (dq.front() == i)  dq.pop_front();
                sum-=runningCosts[i];
                i++;
            }
            if(j-i+1 == mid) 
            {
                long long total = (long long)chargeTimes[dq.front()] + (long long)mid*sum;
                if(total <= budget) return true;
            }
           
        }

        return false;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        int low = 0;
        int high = runningCosts.size();

        while(low < high)
       {
         int mid = low + (high - low + 1)/2;
         if(isPossible(chargeTimes,runningCosts,mid,budget)) low = mid;
         else high = mid - 1; 
       }

       return low;
    }
};