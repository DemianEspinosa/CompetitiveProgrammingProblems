#include <iostream>
#include <string>

using namespace std;

int T, i, j, ans;
string s1, s2;

int main()
{

    cin >> T;

while(T--){

    cin >> s1;
    cin >> s2;
    ans = 0;
    for(i = 0; i < s1.size(); i++)
        if(s1[i] != s2[i])
            ans++;

    cout << ans << endl;

	}
}
