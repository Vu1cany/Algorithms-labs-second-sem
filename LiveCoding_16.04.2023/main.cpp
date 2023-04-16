#include <iostream>
#include "queue"

struct Node{
    int i;
    int j;
    Node(int i, int j){
        this->i = i;
        this->j = j;
    }
};

using namespace std;

int main() {
    queue<Node> queue;
    int n, m;
    cin >> n >> m;

    bool visited[n][m];
    int** matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
            char s;
            cin >> s;
            if (s == '1'){
                visited[i][j] = true;
                queue.push(Node(i, j));

            }
        }
    }

    int timer = 0;

    while (!queue.empty()){
        int length = queue.size();

        for (int i = 0; i < length; ++i) {
            Node current = queue.front();
            queue.pop();

            if (current.j + 1 != m && matrix[current.i][current.j + 1] == 0 && !visited[current.i][current.j + 1]) {
                queue.push(Node(current.i, current.j + 1));
                visited[current.i][current.j + 1] = true;
            }
            if (current.j - 1 >= 0 && matrix[current.i][current.j - 1] == 0 && !visited[current.i][current.j - 1]) {
                queue.push(Node(current.i, current.j - 1));
                visited[current.i][current.j - 1] = true;
            }
            if (current.i + 1 != n && matrix[current.i + 1][current.j] == 0 && !visited[current.i + 1][current.j]) {
                queue.push(Node(current.i + 1, current.j));
                visited[current.i + 1][current.j] = true;
            }
            if (current.i - 1 >= 0 && matrix[current.i - 1][current.j] == 0 && !visited[current.i - 1][current.j]) {
                queue.push(Node(current.i - 1, current.j));
                visited[current.i - 1][current.j] = true;
            }
        }

        timer++;

    }

    cout << timer - 1;

    return 0;
}
