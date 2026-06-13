

class Solution {
public: 

class DSU {
private:
    
    vector<int> rank;
    int components;
  
public:
  vector<int> parent;
    DSU(int n) : parent(n), rank(n, 0), components(n) {
        iota(parent.begin(), parent.end(), 0);  // parent[i] = i
    }  
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    } 
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);  
        if (px == py) {
            return false;  // Already in same set
        }
        // Union by rank
        if (rank[px] < rank[py]) {
            swap(px, py);
        }
        parent[py] = px;
        if (rank[px] == rank[py]) {
            rank[px]++;
        } 
        components--;
        return true;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    } 
    int countComponents() {
        return components;
    }
};
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int cnt =0;
        DSU DSU(v);
         for(int i=0;i<v;i++)
         {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j] == 1) DSU.unite(i,j);
            }
         }

         for(int i=0;i<v;i++)
         {
             if(DSU.parent[i] == i) cnt++;
         }
      return cnt;
    }
};