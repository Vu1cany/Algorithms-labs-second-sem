#include <iostream>

using namespace std;

struct Edge{
    int start;
    int end;
    int weight;
    Edge(){

    }

    Edge(int start, int end, int weight) : start(start), end(end), weight(weight) {}
};

bool relax(int index1, int index2, int weight, int* dist){
    if (dist[index1] == INT_MAX) return false;
    if (dist[index2] > dist[index1] + weight){
        dist[index2] = dist[index1] + weight;
        return true;
    }
    return false;
}

void fordBellman(Edge* edgeList, int m, int n, int* dist){
    for (int j = 0; j < n - 1; ++j) {
        bool endOperation = true;

        for (int i = 0; i < m; ++i) {
            bool result = relax(edgeList[i].start, edgeList[i].end, edgeList[i].weight, dist);
            if (endOperation){
                endOperation = !result;
            }
        }
        if (endOperation) break;
    }
}

int main() {
    int N, M, Q, Start;
    cin >> N >> M >> Q >> Start;
    N++;
    M*= 2;

    Edge edgeList[M];

    int dist[N];
    for (int i = 0; i < N; ++i) {
        dist[i] = INT_MAX;
    }
    dist[Start] = 0;

    for (int i = 0; i < M; i += 2) {
        int start, end, weight;
        cin >> start >> end >> weight;

        edgeList[i] = Edge(start, end, weight);
        edgeList[i + 1] = Edge(end, start, weight);
    }

    fordBellman(edgeList, M, N - 1, dist);

    for (int i = 0; i < Q; ++i) {
        int end;
        cin >> end;
        if (dist[end] == INT_MAX) {
            cout << "-1" << "\n";
        } else {
            cout << dist[end] << "\n";
        }
    }

    return 0;
}
