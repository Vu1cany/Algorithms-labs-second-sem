#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string text;
    cin >> text;
    int counter = 0;
    for (int i = 0; i < M; ++i) {
        int index1, index2, k;
        cin >> index1 >> index2 >> k;
        if (text.substr(index1 - 1, k) == text.substr(index2 - 1, k)){
            counter++;
        }
    }
    cout << counter;
    return 0;
}
