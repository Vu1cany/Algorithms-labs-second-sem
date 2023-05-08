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
    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        edges[i] = Edge(start, end, weight);
    }

    sort(edges.begin(), edges.end());

    DSU dsu = DSU(N);
    for (int i = 1; i < N; ++i) {
        dsu.makeSet(i);
    }

    long long result1 = 0;
    Edge second = Edge(0, 0, 0);
    for (Edge edge : edges) {
        if (dsu.findSet(edge.start) != dsu.findSet(edge.end)){
            result1 += edge.weight;
            dsu.unionSets(edge.start, edge.end);
        } else {
            if (second.start == 0) {
                second = edge;
            }
        }

    }

    dsu = DSU(N);
    for (int i = 1; i < N; ++i) {
        dsu.makeSet(i);
    }
    long long result2 = second.weight;
    dsu.unionSets(second.start, second.end);
    for (Edge edge : edges) {
        if (dsu.findSet(edge.start) != dsu.findSet(edge.end)){
            if (second.start == 0) {
                second = edge;
            }
            result2 += edge.weight;
            dsu.unionSets(edge.start, edge.end);
        }
    }


    cout << result1 << " " << result2;

    return 0;
}
