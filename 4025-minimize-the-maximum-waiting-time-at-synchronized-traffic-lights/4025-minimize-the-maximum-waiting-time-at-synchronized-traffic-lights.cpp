class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        
        sort(lights.begin(),lights.end());
        sort(arrivalTime.begin(),arrivalTime.end());
        int maxi = 0;

        for(int i=0;i<arrivalTime.size();i++)
        {
            int r = arrivalTime[i] % period;
            auto it = upper_bound(lights.begin(),lights.end(),r);
            if(it == lights.end())
            {
                maxi = max(maxi,period-r);
            }
        }

        return maxi;

    }
};