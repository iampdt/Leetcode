class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        
        vector<long long> prefix(tasks.size());
        prefix[0] = tasks[0];
        vector<int> ans(shifts.size());

        for(int i=1;i<tasks.size();i++) prefix[i] = 1LL*prefix[i-1] + 1LL*tasks[i];
        long long lastIdx = 0;
        long long rem = 0;
        for(int i=0;i<shifts.size();i++)
        {
            long long val = shifts[i];
            if(lastIdx > 0) val = 1LL*val + 1LL*prefix[lastIdx-1] + rem;
            else val = 1LL*val + 1LL*rem;
            int idx = upper_bound(prefix.begin(),prefix.end(),val) - prefix.begin();
            if(idx >= tasks.size())
            {
                ans[i] = 0;
                lastIdx = 0;
                rem = 0;
            }
                else if(idx == 0) { ans[i] = tasks.size(); lastIdx = 0; rem = val;}
            else 
            {
                lastIdx = idx;
                rem = val - prefix[idx-1] ;
                ans[i] = tasks.size() - idx;
            }
        }

        return ans;
    } 
};