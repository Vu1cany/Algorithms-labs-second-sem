#include <iostream>
#include <vector>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
};

void visit(vector<vector<int>>& vector, const int& node, Color* visited, bool& flag, const int& start){
    visited[node] = GRAY;

    for (auto nextNode : vector[node]) {
        if (visited[nextNode] == WHITE){
            visit(vector, nextNode, visited, flag, node);

        } else if (visited[nextNode] == GRAY && nextNode != start){
            flag = true;
        }
    }
    visited[node] = BLACK;
}

void dfs(const int& N,vector<vector<int>>& vector, Color* visited, bool& flag){
    for (int i = 1; i < N; ++i) {
        if (visited[i] == WHITE){
            visit(vector, i, visited, flag, i);
        }
        if (flag){
            break;
        }
    }
}

int main() {

    int N,M;
    cin >> N >> M;
    N++;
    vector<vector<int>> vector(N);
    Color visited[N];
    for (int i = 0; i < N; ++i) {
        visited[i] = BLACK;
    }

    for (int i = 0; i < M; ++i) {
        int index, value;
        cin >> index >> value;
        vector[index].push_back(value);
        vector[value].push_back(index);
        visited[index] = WHITE;
        visited[value] = WHITE;
    }

    for (int i = 1; i < N; ++i) {
        std::sort(vector[i].begin(), vector[i].end());
    }

    bool flag = false;
    dfs(N, vector, visited, flag);

    if (flag){
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
