#include <iostream>
#include "regex"

using namespace std;

int main() {
    regex regex1("l+o{2,}x+");
    string str;
    smatch result;

    while(cin >> str){

        if (regex_search(str, result, regex1)){
            str = regex_replace(str, regex1, "XXX");
        }

        cout << str << "\n";
    }
    return 0;
}
