#include <iostream>
#include <cmath>

using namespace std;

int controlBitQuantity(int strLength){
    int count = 0;
    while (pow(2, count) < strLength){
        count++;
    }
    return count + 1;
}

bool isDegreeOfTwo(int value){
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        if ((value >> i) & 1) {
            count++;
        }
    }
    if (count > 1){
        return false;
    } else {
        return true;
    }
}

int main() {
    int strCount;
    cin >> strCount;

    for (int i = 0; i < strCount; ++i) {
        string str;
        cin >> str;
        int controlBitAmount = controlBitQuantity(str.length());
        int controlBitValue = 1;
        int mistakeIndex = 0;

        while (controlBitValue < pow(2, controlBitAmount)){
            int count = 0;
            int iterator = 0;
            for (int j = controlBitValue - 1; j < str.length(); ++j) {
                if (str[j] == '1'){
                    count++;
                }
                iterator++;
                if (iterator == controlBitValue){
                    j += iterator;
                    iterator = 0;
                }
            }
            if (count % 2){
                mistakeIndex += controlBitValue;
            }

            controlBitValue *= 2;
        }

        if (mistakeIndex){
            str[mistakeIndex - 1] = str[mistakeIndex - 1] == '0' ? '1' : '0';
        }

        for (int j = 0; j < str.length(); ++j) {
            if (isDegreeOfTwo(j + 1)){
                continue;
            }
            cout << str[j];
        }
        cout << "\n";

    }
    return 0;
}
