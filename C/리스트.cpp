#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    int i = 0, n;
    list<int> l;

    getline(cin, in);
    while (in[i] != NULL) {
        if (in[i] == ' ') {
            i++;
            continue;
        }
        n = in[i] - '0';
        l.push_back(n);
        i++;
    }

    for (list<int> :: iterator iter = l.begin(); iter != l.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";


    return 0;

}