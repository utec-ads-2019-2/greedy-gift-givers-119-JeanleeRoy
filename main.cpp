#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int count, space = 0;

    while (cin >> count) {
        map <string,int> group;
        string name[10];
        for (int i = 0; i < count; ++i) {
            cin >> name[i];
            group[name[i]] = 0;
        }
        for (int i = 0; i < count; ++i) {
            int frds, amount;
            string member;
            cin >> member >> amount >> frds;
            if (frds > 0) {
                group[member] += (amount%frds - amount);
                for (int j = 0; j < frds; ++j) {
                    string Frd;
                    cin >> Frd;
                    group[Frd] += amount/frds;
                }
            }
        }

        if (space > 0)
            cout << endl;
        space++;

        for (int i = 0; i < count; ++i)
            cout << name[i] << " " << group[name[i]] << endl;

    }

    return 0;
}