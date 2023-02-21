#include <iostream>
#include <cmath>

void readStrings(std::string strings[], int n){
    for (int i = 0; i < n; ++i) {
        std::cin >> strings[i];
    }
}

int main() {
    int strCount;
    std::cin >> strCount;

    std::string stringsInput[strCount];
    readStrings(stringsInput, strCount);

    for (int i = 0; i < strCount; ++i) {
        std::string str = stringsInput[i];
        int controlBitCount = log2(str.length()) + 1;
        int mistakeIndex = -1;
        int controlBitValue = 1; //Значение котрольного бита

        for (int j = 0; j < controlBitCount; ++j) {
            int oneCount = 0;

            for (int k = controlBitValue - 1; k < str.length(); k += controlBitValue * 2) {
                int index = k;
                for (int l = 0; l < controlBitValue; ++l) {
                    if (str[index++] == '1') oneCount++;
                }
            }

            if (oneCount % 2 != 0){
                mistakeIndex += controlBitValue;
            }
            controlBitValue *= 2;
        }

        if (mistakeIndex > -1) {
            if (str[mistakeIndex] == '0') {
                str[mistakeIndex] = '1';
            } else if (str[mistakeIndex] == '1'){
                str[mistakeIndex] = '0';
            }
        }

        for (int j = 0; j < str.length(); ++j) {
            double temp;
            if (modf(log2(j + 1), &temp) > 0) {
                std::cout << str[j];
            }
        }
        std::cout << "\n";

    }

    return 0;
}
