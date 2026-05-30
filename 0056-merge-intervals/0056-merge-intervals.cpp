class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> results;
        results.push_back(intervals[0]);
        int idx = 0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] > results[idx][1]) 
            {
                results.push_back(intervals[i]);
                idx++;
            }
            else 
            {
                results[idx][1] = max(results[idx][1],intervals[i][1]);
            }
        }
        return results;
    }
};