#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    int n, i=0;
    vector<int> v;
    
    getline(cin, in);
    while (in[i] != NULL) {
        if (in[i] == ' ') {
            i++;
            continue;
        }
        n = in[i] - '0';
        v.push_back(n);
        i++;
    }

    //  �ε��� index ���
    for (i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
    
    // �ݺ��� iterator ���
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << " ";
    
    cout << "\n";

    return 0;

}

