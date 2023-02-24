#include <iostream>

using namespace std;

struct numbersNode{
    int value;
    numbersNode* parent = nullptr;
    numbersNode* left = nullptr;
    numbersNode* right = nullptr;
};

struct symbolsNode{
    char value;
    symbolsNode* parent = nullptr;
    symbolsNode* left = nullptr;
    symbolsNode* right = nullptr;
};

int main() {
    //----------------------------INPUT---------------------
    int numbersN, numbersQ;
    cin >> numbersN >> numbersQ;

    int arrNumbersQ[numbersQ];
    numbersNode* arrNumbersN[numbersN];

    for (int i = 0; i < numbersN; ++i) {    //Строим дерево через массив для чисел
        cin >> arrNumbersN[i]->value;

        int leftIndex = i * 2 + 1;
        int rightIndex = i * 2 + 2;

        if (leftIndex < numbersN){
            arrNumbersN[i]->left = arrNumbersN[leftIndex];
            arrNumbersN[leftIndex]->parent = arrNumbersN[i];
        }
        if (rightIndex < numbersN){
            arrNumbersN[i]->right = arrNumbersN[rightIndex];
            arrNumbersN[rightIndex]->parent = arrNumbersN[i];
        }

    }
    for (int i = 0; i < numbersQ; ++i) {
        cin >> arrNumbersQ[i];
        arrNumbersQ[i]--;
    }

    int symbolsN, symbolsQ;
    cin >> symbolsN >> symbolsQ;

    symbolsNode* arrSymbolsN[symbolsN];
    int arrSymbolsQ[symbolsQ];

    for (int i = 0; i < symbolsN; ++i) {    //Строим дерево через массив для символов
        cin >> arrSymbolsN[i]->value;

        int leftIndex = i * 2 + 1;
        int rightIndex = i * 2 + 2;

        if (leftIndex < symbolsN){
            arrSymbolsN[i]->left = arrSymbolsN[leftIndex];
            arrSymbolsN[leftIndex]->parent = arrSymbolsN[i];
        }
        if (rightIndex < symbolsN){
            arrSymbolsN[i]->right = arrSymbolsN[rightIndex];
            arrSymbolsN[rightIndex]->parent = arrSymbolsN[i];
        }
    }

    for (int i = 0; i < symbolsQ; ++i) {
        cin >> arrSymbolsQ[i];
        arrSymbolsQ[i]--;   //Для простоты работы с индексами
    }
    //--------------------------------------------------------







    return 0;
}
