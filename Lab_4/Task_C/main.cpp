#include <iostream>

using namespace std;

struct Edge{
    int start;
    int end;
    int weight;
    Edge(int start, int end, int weight){
        this->start = start;
        this->end = end;
        this->weight = weight;
    }
    Edge(){

    }
};

bool relax(int index1, int index2, int weight, int* dist){
    if (dist[index1] == INT_MAX) return false;

    if (dist[index2] > dist[index1] + weight){
        dist[index2] = dist[index1] + weight;
        return true;
    }
    return false;
}

void fordBellman(Edge* edgeList,int m, int n, int* dist, int& cycleLength){
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

    for (int i = 0; i < m; ++i) {
        bool flag = relax(edgeList[i].start, edgeList[i].end, edgeList[i].weight, dist);
        if (flag){
            cycleLength++;
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int n, m;
        cin >> n >> m;
        n++;
        Edge edgeList[m];

        for (int j = 0; j < m; ++j) {
            cin >> edgeList[j].start >> edgeList[j].end >> edgeList[j].weight;
        }

        int dist[n];
        for (int j = 0; j < n; ++j) {
            dist[i] = INT_MAX;
        }
        dist[1] = 0;

        int cycleLength = 0;

        fordBellman(edgeList,m , n - 1, dist, cycleLength);

        if (cycleLength <= K || cycleLength == 0){
            cout << "YES\n";
        } else {
           cout << "NO\n";
        }

    }
    return 0;
}
