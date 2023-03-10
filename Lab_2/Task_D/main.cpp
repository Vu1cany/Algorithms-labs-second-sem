#include <iostream>
#include <vector>
#include "queue"

using namespace std;

void bfs(vector<vector<int>>& vector, bool* visited, const int& dist1, const int& dist2, int* lengths){
    queue<int> queue;
    queue.push(dist1);

    while (!queue.empty()){
        int node = queue.front();
        queue.pop();
        visited[node] = true;

        for (auto nextNode : vector[node]) {
            if (!visited[nextNode]) {
                if (lengths[nextNode] == 0){
                    lengths[nextNode] = lengths[node] + 1;
                } else {
                    lengths[nextNode] = min(lengths[nextNode], lengths[node] + 1);
                }
                queue.push(nextNode);
            }
        }
    }
}

int main() {
    int N,M;
    cin >> N >> M;
    N++;
    vector<vector<int>> vector(N);
    bool visited[N];

    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < M; ++i) {
        int node1,node2;
        cin >> node1 >> node2;
        vector[node1].push_back(node2);
        vector[node2].push_back(node1);
    }

    int dist1, dist2;
    cin >> dist1 >> dist2;
    int lengths[N];
    for (int i = 0; i < N; ++i) {
        lengths[i] = 0;
    }

    bfs(vector, visited, dist1, dist2, lengths);

    if (lengths[dist2] == 0){
        cout << -1;
    } else {
        cout << lengths[dist2];
    }

    return 0;
}
