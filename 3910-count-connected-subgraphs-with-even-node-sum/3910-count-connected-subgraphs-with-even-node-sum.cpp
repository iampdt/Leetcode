class Solution {
public:
// graph should be connect check with dfs or bfs 
// sum of node values should be even -> nums[i] => sum of those idx 

    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        
        int n = nums.size();
        int total_subsets = (1 << n);

        vector<int> adj[n];
        int validsubset=0;

        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int mask = 1; mask<total_subsets;mask++)
        {
            int sum = 0;
            int nodesub =0;
            int startnode=-1;

            for(int i=0;i<n;i++)
            {
                if((mask >> i) & 1) 
                {
                    sum+=nums[i];
                    nodesub++;
                    startnode = i;

                }
            }
            if(sum&1) continue;

            int visitedmask = 0;
            int nodecount = 0;
            queue<int> q;
            q.push(startnode);
            visitedmask |= (1 << startnode);

            while(!q.empty())
            {
                int curr = q.front();
                q.pop(); 
                nodecount++;

                for(auto it: adj[curr])
                {
                    if( ((mask>>it)&1) && !((visitedmask >> it)&1))
                    {
                        q.push(it);
                        visitedmask |= (1 << it);
                    }
                }
            }
            if(nodecount == nodesub) validsubset++;
        }

     return validsubset;

    }
};