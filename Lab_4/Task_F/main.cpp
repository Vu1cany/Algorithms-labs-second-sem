#include <iostream>
#include <vector>
#include "stack"

using namespace std;

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

struct Query{
    char command;
    int index1;
    int index2;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    n++;

    DSU dsu = DSU(n);
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int index1, index2;
        cin >> index1 >> index2;
        graph[index1].push_back(index2);
        graph[index2].push_back(index1);
    }

    stack<Query> queries;
    stack<string> answers;

    for (int i = 0; i < q; ++i) {
        char command;
        int index1, index2;
        cin >> command >> index1 >> index2;
        if (command == '-'){
            for (int j = 0; j < graph[index1].size(); ++j) {
                if (graph[index1][j] == index2){
                    graph[index1][j] = 0;
                }
            }
            for (int j = 0; j < graph[index2].size(); ++j) {
                if (graph[index2][j] == index1){
                    graph[index2][j] = 0;
                }
            }
        }
        queries.push(Query{command, index1, index2});
    }

    for (int i = 1; i < n; ++i) {
        dsu.makeSet(i);
        for (int vertex : graph[i]) {
            if (vertex == 0) continue;
            dsu.makeSet(vertex);
            dsu.unionSets(i, vertex);
        }
    }

    while (!queries.empty()){
        Query query = queries.top();
        queries.pop();

        switch (query.command) {
            case '-':
                dsu.makeSet(query.index1);
                dsu.makeSet(query.index2);
                dsu.unionSets(query.index1, query.index2);
                break;

            case '?':
                bool flag = dsu.findSet(query.index1) == dsu.findSet(query.index2);
                if (flag){
                    answers.push("YES");
                } else {
                    answers.push("NO");
                }
                break;
        }
    }

    while (!answers.empty()){
        cout << answers.top() << "\n";
        answers.pop();
    }

    return 0;
}
