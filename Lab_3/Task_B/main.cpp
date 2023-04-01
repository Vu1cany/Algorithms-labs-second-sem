#include <iostream>
#include <vector>
using namespace std;

enum Color{
    WHITE,
    GREY,
    BLACK
};

void dfs(vector<vector<int>>& graph, Color* visited, int node, int finish, bool& flag){
    visited[node] = GREY;
    if (node == finish) flag = true;
    for (int nextNode : graph[node]) {
        if (nextNode == 0) continue;

        if (visited[nextNode] == WHITE){
            dfs(graph, visited, nextNode, finish, flag);
        }
    }
    visited[node] = BLACK;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    n++;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int temp1, temp2;
        cin  >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    Color visited[n];

    for (int i = 0; i < q; ++i) {
        char command;
        int a, b;
        cin >> command;
        switch (command) {
            case '-':
                cin >> a >> b;
                for (int j = 0; j < graph[a].size(); ++j) {
                    if (graph[a][j] == b){
                        graph[a][j] = 0;
                    }
                }
                for (int j = 0; j < graph[b].size(); ++j) {
                    if (graph[b][j] == a){
                        graph[b][j] = 0;
                    }
                }
                break;
            case '?':
                for (int i = 0; i < n; ++i) {
                    visited[i] = WHITE;
                }
                cin >> a >> b;
                bool flag = false;
                dfs(graph, visited, a, b, flag);
                if (flag){
                    cout << "YES" << "\n";
                } else {
                    cout << "NO" << "\n";
                }
                break;
        }
    }

    return 0;
}
