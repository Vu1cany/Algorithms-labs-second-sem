#include "iostream"
#include "string"

int main(){
    int n,m,k;
    std::cin >> n >> m >> k;
    std::string strM, strS;
    std::cin >> strM >> strS;

    char symbolM;   //Считанный символ строки маши
    char symbolS;
    int countCharM = 0; //количество повторений конкретного символа
    int countCharS = 0;
    int indexM = 0;
    int indexS = 0;
    int differenceCount = 0;    //Счетчик различных сиволов
    while(indexM < n || indexS < m){
        if (countCharM == 0){
            symbolM = strM[indexM++];
            while (strM[indexM] >= 48 && strM[indexM] <= 57){
                countCharM = countCharM * 10 + (strM[indexM++] - '0');
            }
        }
        if (countCharS == 0){
            symbolS = strS[indexS++];
            while (strS[indexS] >= 48 && strS[indexS] <= 57){
                countCharS = countCharS * 10 + (strS[indexS++] - '0');
            }
        }
        int minimum = std::min(countCharM, countCharS);
        if (symbolM != symbolS) {
            differenceCount += minimum;
        }
        countCharM -= minimum;
        countCharS -= minimum;
    }

    if (differenceCount < k) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

    return 0;
}