#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, int t, bool* visited, vector<vector<int>> &graph, int** matrix, int capacity){
    if (u == t) return capacity;

    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v] && matrix[u][v] > 0){
            int minCapacity = dfs(v, t, visited, graph, matrix, min(capacity, matrix[u][v]));
            if (minCapacity > 0){
                matrix[u][v] -= minCapacity;
                matrix[v][u] += minCapacity;

                return minCapacity;
            }
        }
    }

    return 0;
}

int main() {
    int N, M;
    cin >> N >> M;
    N++;
    int** matrix = new int*[N];
    bool* visited = new bool[N];
    vector<vector<int>> graph(N);

    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < M; ++i) {
        int start, end, capacity;
        cin >> start >> end >> capacity;
        matrix[start][end] = capacity;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int sum = 0;
    int result;
    while (true){
        for (int i = 0; i < N; ++i) {
            visited[i] = false;
        }
        result = dfs(1, N - 1, visited, graph, matrix, INT_MAX);
        if (result == 0) break;
        sum += result;
    }

    cout << sum;

    return 0;
}
