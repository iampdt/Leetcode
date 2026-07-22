class Solution {
public:
    int solve(int idx,int preIdx,vector<pair<int,int>>& vp,vector<vector<int>>& dp)
    {
        if(idx >= vp.size()) return 0;
        if(dp[idx][preIdx+1] != -1) return dp[idx][preIdx+1];
        int not_take = solve(idx+1,preIdx,vp,dp);
        int take = 0;
        if(preIdx == -1 || (vp[idx].first == vp[preIdx].first) || vp[idx].second >= vp[preIdx].second)
        {
            take = vp[idx].second + solve(idx+1,idx,vp,dp);
        }
        return dp[idx][preIdx+1] = max(take,not_take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vp;
        for(int i=0;i<scores.size();i++)
        {
            vp.push_back({ages[i],scores[i]});
        }
        sort(vp.begin(),vp.end());
        for(auto it: vp) cout<<it.first<<" "<<it.second<<endl;
       vector<vector<int>> dp(scores.size()+1,vector<int>(scores.size()+1,-1));
        return solve(0,-1,vp,dp);
    }
};