class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        
        int max_light = *max_element(lights.begin(),lights.end());
        int maxi = 0;

        for(int i=0;i<arrivalTime.size();i++)
        {
            int r = arrivalTime[i] % period;
            if(r >= max_light)
            {
                maxi = max(maxi, period - r);
            }
        }

        return maxi;

    }
};