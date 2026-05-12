class Solution {
public:
    bool check(vector<int>&positions,int m, int mid)
    {
        int cnt = 1;
        int last = positions[0];
        for(int i=1;i<positions.size();i++)
        {
           if(abs(positions[i] - last) >= mid) 
           {
             last = positions[i];
             cnt++;
           }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& positions, int m) {
        sort(positions.begin(),positions.end());
        int low = 1;
        int high = positions[positions.size()-1] - positions[0];

        while(low < high)
        {
            int mid = low + (high - low + 1)/2;
            if(check(positions,m,mid)) low = mid;
            else high = mid - 1;
        }
        return low;
    }
};