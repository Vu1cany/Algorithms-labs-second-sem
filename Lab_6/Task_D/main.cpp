#include <iostream>

using namespace std;

struct Node {    //Структура узла
    int isu = 0;
    int points = 0;
    int height = 1;
    Node *leftChild = nullptr;
    Node *rightChild = nullptr;

    Node(int isu, int points) : isu(isu), points(points) {}

    Node() {}
};

struct AVLThree {
private:

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

    Node *FindMax(Node *p) {    //поиск узла с наибольним ключом в дереве p
        if (p->rightChild == nullptr) {
            return p;
        } else {
            return FindMax(p->rightChild);
        }
    }

    Node *DeleteMax(Node *p) {     // удаление узла с минимальным ключом из дерева p
        if (p->rightChild == nullptr) {
            return p->leftChild;
        } else {
            p->rightChild = DeleteMax(p->rightChild);
        }
        return Balance(p);
    }

public:

    int BalanceFactor(Node *p) {   //Возвращает баланс для конкретного узла
        return Height(p->rightChild) - Height(p->leftChild);
    }

    //Node *root = nullptr;

    Node* Insert(Node* p, int isu, int points) {  //вставка нового ключа

        if(p == nullptr) return new Node(isu, points);

        if(isu < p->isu) {
            p->leftChild = Insert(p->leftChild,isu, points);
        } else {
            p->rightChild = Insert(p->rightChild,isu, points);
        }
        return Balance(p);
    }

    Node *Search(Node *X, int isu) {
        if (X == nullptr || X->isu == isu) {
            return X;
        }
        if (isu < X->isu) {
            return Search(X->leftChild, isu);
        } else {
            return Search(X->rightChild, isu);
        }
    }

    Node *Delete(Node *root, int k) {  // удаление ключа isu из дерева p
        if (root == nullptr) {
            return root;
        }
        if (k < root->isu) {
            root->leftChild = Delete(root->leftChild, k);
        } else if (k > root->isu) {
            root->rightChild = Delete(root->rightChild, k);
        } else if (root->leftChild != nullptr && root->rightChild != nullptr) {
            root->isu = FindMax(root->leftChild)->isu;
            root->points = FindMax(root->leftChild)->points;
            root->leftChild = Delete(root->leftChild, root->isu);
        } else {
            if (root->leftChild != nullptr) {
                root = root->leftChild;
            } else if (root->rightChild != nullptr) {
                root = root->rightChild;
            } else {
                root = nullptr;
            }
        }
        if (root == nullptr) {
            return root;
        }
        return Balance(root);
    }

};

/*class HashTable{
private:



public:



};*/

int hash1(int value, int size){
    return value % size;
}

void average(Node* root, int& count, int& sum) {
    if (root != nullptr) {
        average(root->leftChild, count, sum);
        average(root->rightChild, count, sum);
        sum += root->points;
        count++;
    }
}

void max1(Node* p, int& maximum) {
    if (p != nullptr) {
        max1(p->leftChild, maximum);
        max1(p->rightChild, maximum);
        maximum = max(maximum, p->points);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int size = 999999;
    Node **table = new Node*[size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;
    }
    AVLThree avlThree;

    int M, Q;
    cin >> M >> Q;

    //HashTable hashTable;

    for (int i = 0; i < Q; ++i) {
        char command;
        cin >> command;
        int group;
        int count = 0, sum = 0;
        int max = 0;
        switch (command) {
            case 'a':
                cin >> group;
                average(table[hash1(group, size)], count, sum);
                cout << (count == 0 ? 0 : sum/count) << "\n";
                break;
            case '-':
                int isu;
                cin >> group >> isu;
                table[hash1(group, size)] =
                        avlThree.Delete(table[hash1(group, size)], isu);
                break;
            case '+':
                int points;
                cin >> group >> isu >> points;
                table[hash1(group, size)] =
                        avlThree.Insert(table[hash1(group, size)], isu, points);
                break;
            case 'm':
                cin >> group;
                max = 0;
                max1(table[hash1(group, size)], max);
                cout << max << "\n";
                break;
        }
    }
    return 0;
}
