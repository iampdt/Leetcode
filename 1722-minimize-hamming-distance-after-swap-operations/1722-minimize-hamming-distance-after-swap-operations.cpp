class Solution {
public:
    class DSU 
    {
        private:
        int components;
        vector<int> parents;
        vector<int> rank;
        public:
        DSU(int n): rank(n,0),parents(n),components(n)
        {
           iota(parents.begin(), parents.end(), 0);
        }

        int findParent(int x)
        {
           if (parents[x] != x) {
            parents[x] = findParent(parents[x]);  // Path compression
           }
           return parents[x];
        }

        bool unite(int x, int y)
        {
            int parent_x = findParent(x);
            int parent_y = findParent(y);

            if(parent_x == parent_y) return false; // same group
            if(rank[parent_x] < rank[parent_y]) swap(parent_x,parent_y);
            parents[parent_y] = parent_x;
            if(rank[parent_x] == rank[parent_y]) rank[parent_x]++;
            components--;
            return true;
        }
        bool isConnected(int x , int y)
        {
            return findParent(x) == findParent(y);
        }
    };
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int cnt = 0;
        DSU dsu(n);
        for(int i=0;i<allowedSwaps.size();i++)
        {
            int x = allowedSwaps[i][0];
            int y = allowedSwaps[i][1];

            dsu.unite(x,y);
        }

      unordered_map<int, unordered_map<int, int>> mp;
        for(int i=0;i<n;i++)
        {
         
         int idx = dsu.findParent(i);
         mp[idx][source[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            int idx = dsu.findParent(i);
            if(mp[idx][target[i]] > 0) mp[idx][target[i]]--;
            else cnt++;
        }

        return cnt;
    }
};