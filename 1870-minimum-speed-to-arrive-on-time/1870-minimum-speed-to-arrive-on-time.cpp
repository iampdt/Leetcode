class Solution {
public:   
    bool is_possible(vector<int>&dist, double hour , int ans)
    {
        double time = 0;
        for(int i=0;i<dist.size()-1;i++)
        {
            if(dist[i]%ans==0) time +=dist[i]/ans;
            else time+= ceil((double)dist[i]/ans); 
        } 
        time += (double)dist[dist.size()-1]/ans;
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        if(dist.size()-1 >= hour) return -1;
        int low = 1;
        int high = 1e9;

        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(is_possible(dist,hour,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
        
    }
};