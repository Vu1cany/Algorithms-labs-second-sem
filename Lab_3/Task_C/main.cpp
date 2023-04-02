#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsG(vector<vector<int>>& graphG, bool* visited, stack<int>& nodes, int node){
    visited[node] = true;
    for (int nextNode : graphG[node]) {
        if (!visited[nextNode]){
            dfsG(graphG, visited, nodes, nextNode);
        }
    }
    nodes.push(node);
}

void dfsH(vector<vector<int>>& graphH, bool* visited, int* components, int node, int compCount){
    components[node] = compCount;
    for (int nextNode : graphH[node]) {
        if (components[nextNode] == 0){
            dfsH(graphH, visited, components, nextNode, compCount);
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    n++;

    vector<vector<int>> graphG(n);
    vector<vector<int>> graphH(n);

    for (int i = 0; i < m; ++i) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graphG[temp1].push_back(temp2);
        graphH[temp2].push_back(temp1);
    }

    bool visited[n];
    int components[n];
    int compCount = 1;
    stack<int> nodes;

    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        components[i] = 0;
    }

    for (int i = 1; i < n; ++i) {
        if (!visited[i]){
            dfsG(graphG, visited, nodes, i);
        }
    }

    int iterator = nodes.size();
    for (int i = 0; i < iterator; ++i) {
        int u = nodes.top();
        nodes.pop();
        if (components[u] == 0){
            dfsH(graphH, visited, components, u, compCount);
            compCount++;
        }
    }

    for (int i = 0; i < q; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        if (components[node1] == components[node2]){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
