#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, bool* visited, int v, stack<int>& stack){
    visited[v] = true;
    for (auto vertex : graph[v]) {
        if (!visited[vertex]){
            dfs(graph, visited, vertex, stack);
        }
    }
    stack.push(v);
}

stack<int> topSort(vector<vector<int>>& graph, int n){
    bool visited[n];
    stack<int> stack;
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for (int i = 1; i < n; ++i) {
        if (!visited[i]){
            dfs(graph, visited, i, stack);
        }
    }
    return stack;
}

void relax(int* dist, int index1, int index2, int length){
    if (length == INT_MAX || dist[index1] == INT_MAX) return;

    if (dist[index2] > dist[index1] + length){
        dist[index2] = dist[index1] + length;
    }
}

void DAG(vector<vector<int>> graph, int n, int start, int** matrix, int* dist){
    stack<int> stack = topSort(graph, n);

    for (int i = 0; i < n;++i) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    while (!stack.empty()){
        int v = stack.top();
        stack.pop();
        for (auto vertex : graph[v]) {
            relax(dist, v, vertex, matrix[v][vertex]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    n++;
    int start, end;
    cin >> start >> end;

    int** matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = INT_MAX;
            if (i == j) {
                matrix[i][j] = 0;
            }
        }
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int index1, index2, length;
        cin >> index1 >> index2 >> length;
        matrix[index1][index2] = length;
        graph[index1].push_back(index2);
    }

    int* dist = new int[n];
    DAG(graph, n, start, matrix, dist);

    if (dist[end] == INT_MAX){
        cout << -1 << "\n";
    } else {
        cout << dist[end] << "\n";
    }

    return 0;
}
