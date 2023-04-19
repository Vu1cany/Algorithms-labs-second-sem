#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    n++;

    int** matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                matrix[i][j] = 0;

            } else {
                matrix[i][j] = INT_MAX;
            }
        }
    }
    
    for (int i = 0; i < m; ++i) {
        int index1, index2, length;
        cin >> index1 >> index2 >> length;
        matrix[index1][index2] = length;
        matrix[index2][index1] = length;
    }

    int maximum = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            for (int k = 1; k < n; ++k) {
                if (matrix[j][i] == INT_MAX || matrix[i][k] == INT_MAX) continue;
                matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == INT_MAX) continue;
            maximum = max(maximum, matrix[j][i]);
        }
    }

    cout << maximum;

    return 0;
}
