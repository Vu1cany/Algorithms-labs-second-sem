#include <iostream>
#include <vector>
using namespace std;

enum Color{
    WHITE,
    GREY,
    BLACK
};

void dfs(vector<vector<int>>& graph, Color* visited, int node, int& compCount, int* components, bool* traps, bool* isSafe){
    visited[node] = GREY;

    components[node] = compCount;
    if (!isSafe[compCount]){
        isSafe[compCount] = traps[node];
    }

    for (int nexNode : graph[node]) {
        if (visited[nexNode] == WHITE){
            dfs(graph, visited, nexNode, compCount, components, traps, isSafe);
        }
    }

    visited[node] = BLACK;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    n++;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool traps[n];
    Color visited[n];
    int components[n];
    int compCount = 0;
    bool isSafe[n];

    for (int i = 1; i < n; ++i) {
        cin >> traps[i];
        isSafe[i] = false;
        visited[i] = WHITE;
        components[i] = 0;
    }

    for (int i = 1; i < n; ++i) {
        if (visited[i] == WHITE){
            compCount++;
            dfs(graph, visited, i, compCount, components, traps, isSafe);
        }
    }

    cout << compCount << "\n";
    for (int i = 1; i < n; ++i) {
        cout << components[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= compCount; ++i) {
        cout << isSafe[i] << " ";
    }

    return 0;
}
