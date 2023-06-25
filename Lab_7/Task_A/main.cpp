#include <iostream>
#include <string>
#include <vector>

using namespace std;

void naiveStringMather(string& T, string& X, int& counter, vector<int>& indexes){
    int n = T.size();
    int m = X.size();
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < m; ++j) {
            if (T[i + j] != X[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            counter++;
            indexes.push_back(i);
        }
    }
}

int main() {
    string T, X;
    cin >> T >> X;
    vector<int> indexes;
    int counter = 0;

    naiveStringMather(T, X, counter, indexes);

    cout << counter << "\n";
    for (int index : indexes) {
        cout << index << " ";
    }
    return 0;
}
