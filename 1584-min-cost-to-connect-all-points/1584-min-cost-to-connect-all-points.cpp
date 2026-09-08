class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n+1, INT_MAX);
        dist[0]=0;
        vector<int> vis(n);
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            int u = -1;
            for(int j = 0;j<n;j++)
            {
                if(!vis[j] && (u==-1 || dist[u] > dist[j]))
                {
                    u = j;
                }
               
            }
             vis[u] = true;
             ans+=dist[u];
            

            for(int j=0;j<n;j++)
            {
                if(!vis[j])
                {
                    int k = abs(points[u][0] - points[j][0]) + abs(points[j][1] - points[u][1]);
                    dist[j] = min(k,dist[j]);
                }
            }
        }

        return ans;
    }
};