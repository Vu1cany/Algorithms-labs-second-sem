#include <iostream>
#include <stack>

using namespace std;

bool palindrome(int* array, int m){
    for (int i = 0; i < m; ++i) {
        if (array[i] != array[m * 2 - i - 1]){
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    int array[N];
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    stack<int> myStack;
    for (int i = 0; i <= N / 2; ++i) {
        if (palindrome(array, i)){
            myStack.push(N - i);
        }
    }

    while (!myStack.empty()){
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}