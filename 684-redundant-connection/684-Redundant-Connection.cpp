class Solution { 
    vector<int> parent, sz;  
public:
    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){

        a = find(a);
        b = find(b);

        if(a == b) return false;

        if(sz[a] < sz[b]) swap(a,b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!unite(u, v)) {
                return edge;
            }
        }

        return {};
        
    }
};