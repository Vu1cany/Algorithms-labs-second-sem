#include <iostream>

using namespace std;

void roomSearch(char** house, const int& m, const int& n, const int& startN, const int& startM){

    house[startN][startM] = '#';
    if (startN - 1 >= 0 && house[startN - 1][startM] == '.'){
        roomSearch(house, m, n, startN - 1, startM);
    }
    if (startM - 1 >= 0 && house[startN][startM - 1] == '.'){
        roomSearch(house, m, n, startN, startM - 1);
    }
    if (startN + 1 < n && house[startN + 1][startM] == '.'){
        roomSearch(house, m, n, startN + 1, startM);
    }
    if (startM + 1 < m && house[startN][startM + 1] == '.'){
        roomSearch(house, m, n, startN, startM + 1);
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    char** house = new char*[n];
    for (int i = 0; i < n; ++i) {
        house[i] = new char[m];
        for (int j = 0; j < m; ++j) {
            cin >> house[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (house[i][j] == '.'){
                roomSearch(house, m, n, i, j);
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
