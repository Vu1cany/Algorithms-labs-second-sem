#include <iostream>
#include <vector>

using namespace std;

bool dfs(int** matrix, bool** visited, pair<int, int>** mt, int u, int v, int N, int M){
    if (visited[u][v]) return false;

    visited[u][v] = true;

    if (u > 1 && matrix[u - 1][v] != INT_MAX){
        if (mt[u - 1][v] == pair<int, int>{-1, -1} || dfs(matrix, visited, mt, mt[u - 1][v].first, mt[u - 1][v].second, N, M)){
            mt[u - 1][v] = {u, v};
            return true;
        }
    }

    if (u < N-1 && matrix[u + 1][v] != INT_MAX){
        if (mt[u + 1][v] == pair<int, int>{-1, -1} || dfs(matrix, visited, mt, mt[u + 1][v].first, mt[u + 1][v].second, N, M)){
            mt[u + 1][v] = {u, v};
            return true;
        }
    }

    if (v > 1  && matrix[u][v - 1] != INT_MAX){
        if (mt[u][v - 1] == pair<int, int>{-1, -1} || dfs(matrix, visited, mt, mt[u][v - 1].first, mt[u][v - 1].second, N, M)){
            mt[u][v - 1] = {u, v};
            return true;
        }
    }

    if (v < M-1 && matrix[u][v + 1] != INT_MAX){
        if (mt[u][v + 1] == pair<int, int>{-1, -1} || dfs(matrix, visited, mt, mt[u][v + 1].first, mt[u][v + 1].second, N, M)){
            mt[u][v + 1] = {u, v};
            return true;
        }
    }

    return false;
}

void clear(bool** visited, int N, int M){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = false;
        }
    }
}

int main() {
    int N,M;
    cin >> N >> M;
    N++;
    M++;
    bool** visited = new bool *[N];
    auto** mt = new pair<int, int>* [N];
    int** matrix = new int *[N];

    for (int i = 0; i < N; ++i) {
        visited[i] = new bool[M];
        mt[i] = new pair<int, int>[M];
        matrix[i] = new int[M];

        for (int j = 0; j < M; ++j) {
            visited[i][j] = false;
            matrix[i][j] = 0;
            mt[i][j] = pair<int, int>(-1, -1);
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int v, u;
        cin >> v >> u;
        matrix[v][u] = INT_MAX;
    }

    int count = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            if (matrix[i][j] != INT_MAX){
                clear(visited, N, M);
                count += dfs(matrix, visited, mt, i, j, N, M);
            }
        }
    }

    cout << count;


    return 0;
}
