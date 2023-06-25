#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(vector<int>& cards, int m) {
    bool palindrome = true;
    for (int i = 0; i < m; i++) {
        if (cards[i] != cards[m * 2 - i - 1]) {
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

int poker() {
    int N, M;
    cin >> N >> M;
    vector<int> cards;
    for (int i = 0; i < N; i++) {
        int card;
        cin >> card;
        cards.push_back(card);
    }
    vector<int> res;
    for (int i = 0; i <= N / 2; i++) {
        if (isPalindrome(cards, i)) {
            res.push_back(cards.size() - i);
        }
    }
    for (auto iter = res.end() - 1; iter != res.begin() - 1; iter--) {
        cout << *iter << " ";
    }
    return 0;
}