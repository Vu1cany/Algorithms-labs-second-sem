#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int start;
    int end;
    int weight;

    Edge(int start, int anEnd, int weight) : start(start), end(anEnd), weight(weight) {};
    Edge() = default;

    bool operator < (Edge edge) const{
        return weight < edge.weight;
    }
};

struct DSU{
    int* parent;
    int* size;

    DSU(int n){
        this->parent = new int[n];
        this->size = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = 0;
            size[i] = 0;
        }
    }

    void makeSet(int v){
        if (parent[v] == 0){
            parent[v] = v;
            size[v] = 1;
        }
    }

    int findSet(int v){
        if (v == parent[v]){
            return v;
        } else {
            return parent[v] = findSet(parent[v]);
        }
    }

    void unionSets(int v, int u){
        int x = findSet(v);
        int y = findSet(u);
        if (x != y) {
            if (size[x] < size[y])
                swap (x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    N++;
    vector<Edge> edges1(M);
    vector<Edge> edges2(M);
    for (int i = 0; i < M; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        edges1[i] = Edge(start, end, weight);
        edges2[i] = Edge(start, end, weight);
    }

    sort(edges1.begin(), edges1.end());

    int result[M];
    for (int i = 0; i < M; ++i) {
        result[i] = 0;
        DSU dsu = DSU(N);

        for (int j = 1; j < N; ++j) {
            dsu.makeSet(j);
        }

        result[i] += edges2[i].weight;
        dsu.unionSets(edges2[i].start, edges2[i].end);

        for (Edge edge : edges1) {
            if (dsu.findSet(edge.start) != dsu.findSet(edge.end)){
                result[i] += edge.weight;
                dsu.unionSets(edge.start, edge.end);
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
