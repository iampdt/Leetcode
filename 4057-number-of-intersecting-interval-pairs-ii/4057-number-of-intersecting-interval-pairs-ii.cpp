class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        
        long long count = 0;
        vector<int> start;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++) { start.push_back(intervals[i][0]); }

        for(int i=0;i<intervals.size();i++)
        {
            int idx = upper_bound(start.begin(),start.end(),intervals[i][1]) - start.begin();
            if(idx > 0) count += (1LL*idx - 1LL*i - 1LL*1);
        }

        return count;
    }
    
};