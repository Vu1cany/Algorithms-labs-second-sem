#include <iostream>

using namespace std;

struct AVLThree {
private:
    struct Node {    //Структура узла
        int key = 0;
        int height = 1;
        Node *leftChild = nullptr;
        Node *rightChild = nullptr;

        Node(int k) { key = k; }
    };

    int Height(Node *p) {  //Для поулчения высоты конкретного узла
        if (p == nullptr) {
            return 0;
        } else {
            return p->height;
        }
    }

    void NewHeight(Node *p) {    //Восстановаление высоты поддерева в узле
        int left = Height(p->leftChild);
        int right = Height(p->rightChild);
        p->height = max(left, right) + 1;
    }

    Node *RR(Node *p) {    //Правый поворот вокруг p
        Node *q = p->leftChild;
        p->leftChild = q->rightChild;
        q->rightChild = p;
        NewHeight(p);
        NewHeight(q);
        return q;
    }

    Node *RL(Node *q) {     // левый поворот вокруг q
        Node *p = q->rightChild;
        q->rightChild = p->leftChild;
        p->leftChild = q;
        NewHeight(q);
        NewHeight(p);
        return p;
    }

    Node *Balance(Node *p) {    //Балансировка узла
        NewHeight(p);
        if (BalanceFactor(p) == 2) {
            if (BalanceFactor(p->rightChild) < 0) {
                p->rightChild = RR(p->rightChild);
            }
            return RL(p);
        }
        if (BalanceFactor(p) == -2) {
            if (BalanceFactor(p->leftChild) > 0) {
                p->leftChild = RL(p->leftChild);
            }
            return RR(p);
        }
        return p; // Если балансировка не нужна
    }

    int BalanceFactor(Node *p) {   //Возвращает баланс для конкретного узла
        return Height(p->rightChild) - Height(p->leftChild);
    }


public:
    Node* Insert(Node* p, int k) {  //вставка нового ключа

        if(p == nullptr) return new Node(k);

        if(k < p->key) {
            p->leftChild = Insert(p->leftChild,k);
        } else {
            p->rightChild = Insert(p->rightChild,k);
        }
        return Balance(p);
    }

    Node *root = nullptr;

    Node *Search(Node *X, int k) {
        if (X == nullptr || X->key == k) {
            return X;
        }
        if (k < X->key) {
            return Search(X->leftChild, k);
        } else {
            return Search(X->rightChild, k);
        }
    }

};

int simpleHash(int a, int size){
    return abs(a) % size;
}

int main() {
    int N;
    cin >> N;

    int size = 2567;
    AVLThree hashTable[size];

    if (N == 0){
        cout << "YES";
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        int index = simpleHash(temp, size);
        hashTable[index].root = hashTable[index].Insert(hashTable[index].root, temp);
    }

    bool flag = false;

    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        int index = simpleHash(temp, size);
        if (hashTable[index].Search(hashTable[index].root, temp) == nullptr){
            flag = true;
        }
    }

    if (flag){
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}
