#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Hogwarts14 {
private:
    string spell;
    int sizeSpell;
public:
    Hogwarts14(string spell) {
        this->spell = std::move(spell);
        sizeSpell = (int) this->spell.size();
    }

    void suffix() {
        vector<int> res(sizeSpell, 0);
        for (int i = 1; i < sizeSpell; i++) {
            int j = res[i - 1];
            while (j != 0 && spell[i] != spell[j]) {
                j = res[j - 1];
            }
            if (spell[i] == spell[j]) j++;
            res[i] = j;
        }
        for (int i : res) {
            cout << i << " ";
        }
    }
};

int main() {
    string N;
    cin >> N;
    Hogwarts14 hogwarts(N);
    hogwarts.suffix();
    return 0;
}