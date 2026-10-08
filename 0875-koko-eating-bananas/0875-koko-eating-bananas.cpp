class Solution {
public:
    bool isValid(vector<int>& piles,int h,int mid)
    {
        int count = 0;
        for(int i =0;i<piles.size();i++)
        {
            if(piles[i]%mid == 0) count += piles[i]/mid;
            else count+= piles[i]/mid + 1;
        }

        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low < high)
        {
            int mid = low + (high-low)/2;
            if(isValid(piles,h,mid)) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};