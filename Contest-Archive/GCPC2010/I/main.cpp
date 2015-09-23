#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
int T, i, a, b;
string str1, str2;

int main()
{

    cin >> T;
    while (T--){

        m.clear();
        for (i = 0; i < 16; i++){

            cin >> str1 >> str2 >> a >> b;
            (a > b ? m[str1]++ : m[str2]++);

        }

        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
            if (it->second == 4)
                cout << it->first << endl;

    }

}
