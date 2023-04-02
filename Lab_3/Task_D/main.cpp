#include <iostream>
#include <vector>
#include "stack"

using namespace std;

enum Color{
    WHITE,
    GREY,
    BLACK
};

void dfs(vector<vector<int>>& graph, Color* visited, stack<int>& nodes,  int node){
    visited[node] = GREY;
    for (int nextNode : graph[node]) {
        if (visited[nextNode] == WHITE){
            dfs(graph, visited, nodes, nextNode);
        }
    }
    visited[node] = BLACK;
    nodes.push(node);
}

void topologicalSort(vector<vector<int>>& graph, Color* visited, stack<int>& nodes){
    for (int i = 1; i < graph.size(); ++i) {
        if (visited[i] == WHITE){
            dfs(graph, visited, nodes, i);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    n++;

    vector<vector<int>> graph(n);
    Color visited[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = WHITE;
    }

    for (int i = 0; i < m; ++i) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
    }

    stack<int> sortedNodes;
    topologicalSort(graph, visited, sortedNodes);

    int nodes[n];
    int iterator = sortedNodes.size();
    for (int i = 1; i <= iterator; ++i) {
        nodes[sortedNodes.top()] = i;
        sortedNodes.pop();
    }
    for (int i = 1; i < n; ++i) {
        cout << nodes[i] << " ";
    }


    return 0;
}
