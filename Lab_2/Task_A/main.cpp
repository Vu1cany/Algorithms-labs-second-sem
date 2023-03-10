#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    const int count = pow(2, n);
    bool **grayCodes = new bool*[count];
    for (int i = 0; i < count; ++i) {
        grayCodes[i] = new bool[n];
    }

    grayCodes[0][n-1] = false;
    grayCodes[1][n-1] = true;
    int p = 2;
    for (int i = 2; i <= n; ++i) {
        int t = p - 1;
        p = p * 2;
        for (int j = p / 2; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                grayCodes[j][k] = grayCodes[t][k];
            }
            grayCodes[t][n - i] = false;
            grayCodes[j][n - i] = true;
            t--;
        }
    }
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grayCodes[i][j];
        }
        cout << "\n";
    }
    return 0;
}
