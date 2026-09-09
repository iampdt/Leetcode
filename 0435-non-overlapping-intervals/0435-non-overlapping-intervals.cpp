class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y) {
    return x[0] < y[0];
});
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int count = 0;
        for(int i=0;i<intervals.size();i++)
        {
            int j = ans.size()-1;
            if(intervals[i][0] < ans[j][1]) 
            {
                ans[j][1] = min(ans[j][1],intervals[i][1]); 
                count++;
            }
            else ans.push_back(intervals[i]); 
        }
        for(int i=0;i<intervals.size();i++)
        {
            for(int j=0;j<intervals[0].size();j++)
            {
                cout<<intervals[i][j]<<" ";
            }
            cout<<endl;

        }
        cout<<endl;
        cout<<endl;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[0].size();j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;

        }
        return intervals.size()-ans.size();
    }
};