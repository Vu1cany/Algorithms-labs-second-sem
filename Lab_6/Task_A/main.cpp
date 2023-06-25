#include <iostream>

using namespace std;

class HashTable{
private:
    struct Node{
        int value = INT_MIN;
        bool deleted = false;
    };

    int size = 55677;
    Node* table = new Node[size];

    int hash(int key, int i){
        return key % size + i;
    }

public:
    void insert(int key){
        int x = hash(key, 0);

        for (int i = 0; i < size - 1; ++i) {
            if (table[x].value == INT_MIN || table[x].deleted){
                table[x].value = key;
                table[x].deleted = false;
                return;

            } else {
                x = hash(key, i);
            }
        }
    }

    bool search(int key){
        int x = hash(key, 0);
        for (int i = 0; i < size - 1; ++i) {
            if (table[x].value == key && !table[x].deleted){
                return true;

            } else if (table[x].value == INT_MIN || table[x].deleted){
                return false;

            } else {
                x = hash(key, i);
            }
        }
        return false;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    HashTable hashTableX;
    HashTable hashTableY;

    int count = 0;

    for (int i = 0; i < N; ++i) {
        int x,y;
        cin >> x >> y;

        if (!hashTableX.search(x) && !hashTableY.search(y)){
            count++;
            if (count < 4){
                hashTableX.insert(x);
                hashTableY.insert(y);
            }
        }
    }

    if (count == 3){
        cout << "YES";

    } else {
        cout << "NO";
    }

    return 0;
}
