#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    map<string, string> m;

    for (int j = 0; j < 2; j++) {
        cin >> s1 >> s2;

        for (int i = 0; i < s1.size(); i++) {
            s1[i] = toupper(s1[i]);
        }

        m.insert(pair<string, string>(s1, s2));
    }

    for (map<string, string> :: iterator iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first << " : " << iter->second << "\n";
    
    
    return 0;

}