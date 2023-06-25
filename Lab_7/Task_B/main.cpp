#include <iostream>
#include <string>

using namespace std;

int* prefixFunction(string& X) {
    int n = X.length();
    int* array = new int[n];

    for (int i=1; i<n; ++i) {
        int j = array[i-1];
        while (j > 0 && X[i] != X[j])
            j = array[j-1];
        if (X[i] == X[j])  ++j;
        array[i] = j;
    }
    return array;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    int* answer = prefixFunction(str);

    for (int i = 0; i < str.length(); ++i) {
        cout << answer[i] << " ";
    }

    return 0;
}
