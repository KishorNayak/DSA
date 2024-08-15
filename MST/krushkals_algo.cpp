class DisjointSet {
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int v) {
        parent.resize(v + 1);
        for (int i = 0; i <= v; i++) parent[i] = i;
        size.resize(v + 1, 1);
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unionSets(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        if (parentU == parentV) return;

        if (size[parentU] < size[parentV]) {
            parent[parentU] = parentV;
        } else if (size[parentU] > size[parentV]) {
            parent[parentV] = parentU;
        } else {
            parent[parentV] = parentU;
            size[parentU]++;
        }
    }
};

class Solution {
public:
    static bool compare(const vector<int>& t1, const vector<int>& t2) {
        return t1[2] < t2[2];
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        DisjointSet ds(V);
        vector<vector<int>> edges;

        for (int i = 0; i < V; i++) {
            for (auto& edge : adj[i]) {
                edges.push_back({i, edge[0], edge[1]});
            }
        }

        sort(edges.begin(), edges.end(), compare);

        int cnt = 0;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (ds.find(u) != ds.find(v)) {
                cnt += weight;
                ds.unionSets(u, v);
            }
        }

        return cnt;
    }
};
