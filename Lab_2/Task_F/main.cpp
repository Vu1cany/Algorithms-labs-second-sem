#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& vector, bool* visited, const int& dist1){
    queue<int> queue;
    queue.push(dist1);

    while (!queue.empty()){
        int node = queue.front();
        queue.pop();
        visited[node] = true;

        for (auto nextNode : vector[node]) {
            if (!visited[nextNode]) {
                queue.push(nextNode);
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    n++;
    vector<vector<int>> vector(n);
    bool visited[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }

    int node1, node2;
    for (int i = 0; i < m; ++i) {
        cin >> node1 >> node2;
        vector[node1].push_back(node2);
        vector[node2].push_back(node1);
    }

    bfs(vector, visited, node1);


    bool flag = false;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; ++i) {
        if (vector[i].empty()) continue;

        if (!visited[i]){
            flag = true;
            break;
        }

        if (vector[i].size() == 1){
            count1++;
        } else if (vector[i].size() == 2){
            count2++;
        } else {
            flag = true;
            break;
        }
    }

    if (count1 == 2 && (count2 + count1 + 1) == n && !flag){
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
