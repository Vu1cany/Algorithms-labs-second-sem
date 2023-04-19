#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    n++;

    int** matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < m; ++i) {
        int index1, index2, weight;
        cin >> index1 >> index2 >> weight;
        matrix[index1][index2] = weight;
    }

    //Алгоритм флойда-уоршала
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            for (int l = 1; l < n; ++l) {
                if (abs(j - i) > k || abs(l - i) > k) continue;
                if (matrix[j][i] == INT_MAX || matrix[i][l] == INT_MAX) continue;
                matrix[j][l] = min(matrix[j][l], matrix[j][i] + matrix[i][l]);
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int index1, index2;
        cin >> index1 >> index2;
        if (matrix[index1][index2] == INT_MAX) {
            cout << "-1" << "\n";
        } else {
            cout << matrix[index1][index2] << "\n";
        }
    }

    return 0;
}
