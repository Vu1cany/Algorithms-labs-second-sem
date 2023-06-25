#include <iostream>

using namespace std;

int main() {

    int counts1[1000000]{0};
    int counts2[1000000]{0};
    int N;
    cin >> N;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        int index = temp - i;

        if (index >= 0) {
            count += counts1[index];
            counts1[index]++;
        } else {
            index = abs(index);

            count += counts2[index];
            counts2[index]++;
        }
    }

    cout << count;

    return 0;
}
