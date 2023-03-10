#include <iostream>
#include <vector>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
};

void visit(vector<vector<int>>& vector, const int& node, Color* visited, const int& count, int* component){
    visited[node] = GRAY;
    component[node] = count;
    for (int nextNode : vector[node]) {
        if (visited[nextNode] == WHITE){
            visit(vector, nextNode, visited, count, component);
        }
    }
    visited[node] = BLACK;
}

void dfs(const int& n,vector<vector<int>>& vector, Color* visited, int* component){
    for (int i = 0; i < n; ++i) {
        component[i] = 0;
    }

    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (visited[i] == WHITE){
            visit(vector, i, visited, count, component);
        }
        count++;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    n++;
    vector<vector<int>> vector(n);
    Color visited[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = BLACK;
    }

    for (int i = 0; i < m; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        visited[node1] = WHITE;
        visited[node2] = WHITE;
        vector[node1].push_back(node2);
        vector[node2].push_back(node1);
    }

    for (int i = 1; i < n; ++i) {
        std::sort(vector[i].begin(), vector[i].end());
    }

    int component[n];

    dfs(n, vector, visited, component);
    for (int i = 0; i < n; ++i) {
        if (component[i] > 1){
            cout << "NO";
        }
    }
    cout << "YES";

    return 0;
}
