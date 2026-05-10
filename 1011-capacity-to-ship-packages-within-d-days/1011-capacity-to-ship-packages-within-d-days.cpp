class Solution {
public:
    bool helper(vector<int>&weights,int days,int mid)
    {
        int cnt = 1;
        int current_weight = 0;
        for(int i=0;i<weights.size();i++)
        {
           current_weight += weights[i];
           if(current_weight > mid) 
           {
             cnt++;
             current_weight = weights[i];
           }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(helper(weights,days,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};