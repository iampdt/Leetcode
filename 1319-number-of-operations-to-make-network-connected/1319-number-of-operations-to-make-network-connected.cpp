class Solution {
public:
    class DSU
    {
        private:
            vector<int> parent;
            int components;
            vector<int> sz;
        public:
          DSU(int n) : parent(n), sz(n, 1), components(n)
          {
             iota(parent.begin(),parent.end(),0);
          }

          int findParent(int x)
          {
            if(parent[x] != x) return parent[x] = findParent(parent[x]); // path compresion
            return parent[x];
          }

          bool unite(int x,int y)
          {
            int px = findParent(x);
            int py = findParent(y);
            if(px == py) return false;
            if(sz[px] < sz[py]) swap(px,py);
            parent[py] = px;
            sz[px]+=sz[py];
            components--;
            return true;
          }

          bool isConnected(int x,int y)
          {
             return findParent(x) == findParent(y);
          }

          int totalComponents()
          {
            return components;
          }


    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n);
        int cnt = 0;
        for(int i=0;i<connections.size();i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
        }
        DSU dsu(n);
        for(int i=0;i<adj.size();i++)
        {
        for(auto it: adj[i])
        {
           if(!dsu.unite(i,it)) cnt++;
        }
        }
        int components = dsu.totalComponents();
        return cnt >= components - 1 ? components - 1 : -1;
    }
};