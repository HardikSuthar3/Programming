//
// Created by Hardik on 10/07/16.
//



#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class element {
 public:
    string name;
    set<char> nset;

    element(string str) {
        this->name = str;
        for (int64_t i = 0; i < str.length(); ++i) {
            nset.insert(name[i]);
        }
    }
};

void APAC() {
    int64_t T;
    int64_t n;
    fstream out;
    out.open("/Users/Hardik/Documents/op.txt", ios::out);
    cin >> T;
    int64_t cnt = 1;
    while (T > 0) {
        T--;
        cin >> n;
        cin.ignore();
        vector<element *> vector1;
        for (int64_t i = 0; i < n; ++i) {
            string str;
            getline(std::cin, str);
            element *e = new element(str);
            vector1.push_back(e);
        }
        vector<element *>::iterator
                iterator1 = max_element(vector1.begin(), vector1.end(), [](element *a, element *b) -> bool {
            if (a->nset.size() < b->nset.size())
                return true;
            else if (a->nset.size() > b->nset.size()) {
                return false;
            }
            else {
                return a->name > b->name;
            }
        });

        out << "Case #" << cnt++ << ": " << (*iterator1)->name << endl;

    }

    out.close();
}