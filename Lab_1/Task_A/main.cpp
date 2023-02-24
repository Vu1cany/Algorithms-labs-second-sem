#include <iostream>

using namespace std;

/*
7 2
2 3 2 3 4 1 2
2 6
7 1
M O S K L A B
3
 */

struct numbersNode{
    int value = 0;
    numbersNode* parent = nullptr;
    numbersNode* left = nullptr;
    numbersNode* right = nullptr;
};

struct symbolsNode{
    char value = 0;
    symbolsNode* parent = nullptr;
    symbolsNode* left = nullptr;
    symbolsNode* right = nullptr;
};

void numbersLRV(numbersNode* root, int* numbers, int& n){
    if (root != nullptr){
        numbersLRV(root->left, numbers, n);
        numbersLRV(root->right, numbers, n);
        numbers[n] = root->value;
        n++;
    }
}

void symbolsLRV(symbolsNode* root, char* symbols, int& n){
    if (root != nullptr){
        symbolsLRV(root->left, symbols, n);
        symbolsLRV(root->right, symbols, n);
        symbols[n] = root->value;
        n++;
    }
}

int main() {
    int numbersN, numbersQ;
    cin >> numbersN >> numbersQ;

    numbersNode** arrNumbersNode = new numbersNode*[numbersN];

    for (int i = 0; i < numbersN; ++i) {
        arrNumbersNode[i] = new numbersNode;
    }

    numbersNode* numbersRoot = nullptr;

    for (int i = 0; i < numbersN; ++i) {    //Строим дерево через массив для чисел
        cin >> arrNumbersNode[i]->value;

        if (numbersRoot == nullptr){
            numbersRoot = arrNumbersNode[i];
        }

        int leftIndex = i * 2 + 1;
        int rightIndex = i * 2 + 2;

        if (leftIndex < numbersN){
            arrNumbersNode[i]->left = arrNumbersNode[leftIndex];
            arrNumbersNode[leftIndex]->parent = arrNumbersNode[i];
        }
        if (rightIndex < numbersN){
            arrNumbersNode[i]->right = arrNumbersNode[rightIndex];
            arrNumbersNode[rightIndex]->parent = arrNumbersNode[i];
        }

    }

    for (int i = 0; i < numbersQ; ++i) {    //Делаем свапы в дереве чисел
        int index;
        cin >> index;
        index--;   //Для простоты работы с индексами

        numbersNode* current = arrNumbersNode[index];
        numbersNode* parent;
        if (current->parent != nullptr){
            parent = current->parent;

            if (parent->left == current){
                parent->left = current->left;
                if (current->left != nullptr){
                    current->left->parent = parent;
                }
                current->left = parent;
                current->parent = parent->parent;
                parent->parent = current;
                if (current->parent != nullptr){
                    if (current->parent->left == parent){
                        current->parent->left = current;
                    } else if (current->parent->right == parent){
                        current->parent->right = current;
                    }
                }

            } else if (parent->right == current){
                parent->right = current->right;
                if (current->right != nullptr){
                    current->right->parent = parent;
                }
                current->right = parent;
                current->parent = parent->parent;
                parent->parent = current;
                if (current->parent != nullptr){
                    if (current->parent->left == parent){
                        current->parent->left = current;
                    } else if (current->parent->right == parent){
                        current->parent->right = current;
                    }
                }
            }
            if (parent == numbersRoot){
                numbersRoot = current;
            }
        }
    }

    int symbolsN, symbolsQ;
    cin >> symbolsN >> symbolsQ;

    symbolsNode** arrSymbolsNode = new symbolsNode*[symbolsN];

    for (int i = 0; i < symbolsN; ++i) {
        arrSymbolsNode[i] = new symbolsNode;
    }

    symbolsNode* symbolsRoot = nullptr;

    for (int i = 0; i < symbolsN; ++i) {    //Строим дерево через массив для символов
        cin >> arrSymbolsNode[i]->value;

        if (symbolsRoot == nullptr){
            symbolsRoot = arrSymbolsNode[i];
        }

        int leftIndex = i * 2 + 1;
        int rightIndex = i * 2 + 2;

        if (leftIndex < symbolsN){
            arrSymbolsNode[i]->left = arrSymbolsNode[leftIndex];
            arrSymbolsNode[leftIndex]->parent = arrSymbolsNode[i];
        }
        if (rightIndex < symbolsN){
            arrSymbolsNode[i]->right = arrSymbolsNode[rightIndex];
            arrSymbolsNode[rightIndex]->parent = arrSymbolsNode[i];
        }
    }

    for (int i = 0; i < symbolsQ; ++i) {    //Делаем свапы в дереве символов
        int index;
        cin >> index;
        index--;   //Для простоты работы с индексами

        symbolsNode* current = arrSymbolsNode[index];
        symbolsNode* parent;
        if (current->parent != nullptr){
            parent = current->parent;

            if (parent == symbolsRoot){
                symbolsRoot = current;
            }

            if (parent->left == current){
                parent->left = current->left;
                if (current->left != nullptr){
                    current->left->parent = parent;
                }
                current->left = parent;
                current->parent = parent->parent;
                parent->parent = current;
                if (current->parent != nullptr){
                    if (current->parent->left == parent){
                        current->parent->left = current;
                    } else if (current->parent->right == parent){
                        current->parent->right = current;
                    }
                }

            } else if (parent->right == current){
                parent->right = current->right;
                if (current->right != nullptr){
                    current->right->parent = parent;
                }
                current->right = parent;
                current->parent = parent->parent;
                parent->parent = current;
                if (current->parent != nullptr){
                    if (current->parent->left == parent){
                        current->parent->left = current;
                    } else if (current->parent->right == parent){
                        current->parent->right = current;
                    }
                }
            }
        }
    }

    int arrNumbers[numbersN];
    char arrSymbols[symbolsN];
    int n = 0;
    numbersLRV(numbersRoot, arrNumbers, n);
    n = 0;
    symbolsLRV(symbolsRoot, arrSymbols, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < arrNumbers[i]; ++j) {
            cout << arrSymbols[i];
        }
    }

    return 0;
}
