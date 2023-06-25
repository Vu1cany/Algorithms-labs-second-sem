#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Hashtable{
private:
    int size = 2000001;
    vector<string> table = vector<string>(size, "");
    int alphabetSize = 45;
    int k = alphabetSize;
    vector<bool> check = vector<bool>(size, false);

    int hash1(string str){
        int result = (int) str[0];

        for (int i = 1; i < str.size(); ++i) {
            result += str[i] * pow(k, i);
        }

        return abs(result % size);
    }

    int hash2(string str){
        int result = (int) str[0];

        for (int i = 1; i < str.size(); ++i) {
            result += str[i] * pow(k, i);
        }

        return abs(result % (size - 3));
    }

public:
    void insert(string str){
        int h1 = hash1(str);
        int h2 = hash2(str);

        while (true){
            if (table[h1].empty() && !check[h1]){
                table[h1] = str;
                check[h1] = true;
                return;

            } else if (table[h2].empty() && !check[h2]){
                table[h2] = str;
                check[h2] = true;
                return;

            } else{
                swap(str, table[h1]);
                h1 = hash1(str);
                h2 = hash2(str);
            }
        }
    }

    bool contains(string str){
        int h1 = hash1(str);
        int h2 = hash2(str);

        if (table[h1] == str || table[h2] == str) {
            return true;
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

    Hashtable hashtable1;
    Hashtable hashtable2;

    int sum1 = N * 3;
    int sum2 = N * 3;
    int sum3 = N * 3;

    //Задачи перовго друга
    for (int i = 0; i < N; ++i) {
        string str1;
        cin >> str1;

        if (!hashtable1.contains(str1)){
            hashtable1.insert(str1);
        }
    }

    //Задачи второго друга
    for (int i = 0; i < N; ++i) {
        string str2;
        cin >> str2;
        if (hashtable1.contains(str2)){
            sum1 = sum1 - 2;
            sum2 = sum2 - 2;
        }

        if (!hashtable2.contains(str2)){
            hashtable2.insert(str2);
        }
    }

    //Задачи третьего друга
    for (int i = 0; i < N; ++i) {
        string str3;
        cin >> str3;

        if (hashtable1.contains(str3) && hashtable2.contains(str3)){
            sum1--;
            sum2--;
            sum3 = sum3 - 3;

        } else if (hashtable1.contains(str3)){
            sum1 = sum1 - 2;
            sum3 = sum3 - 2;

        } else if (hashtable2.contains(str3)){
            sum2 = sum2 - 2;
            sum3 = sum3 - 2;
        }
    }

    cout << sum1 << " " << sum2 << " " << sum3;


    return 0;
}
