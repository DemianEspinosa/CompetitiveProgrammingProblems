#include <iostream>
#include <cstdio>

using namespace std;

char g[1005][6];

int N;

int main() {
    int i;
    cin >> N;
    
    for (i = 0; i < N; i++)
        scanf("%s", g[i]);
    
    for (i = 0; i < N; i++) {
	    if (g[i][0] == 'O' && g[i][1] == 'O') {
		    g[i][0] = '+';
		    g[i][1] = '+';
		    break;
	    }
	    if (g[i][3] == 'O' && g[i][4] == 'O') {
		    g[i][3] = '+';
		    g[i][4] = '+';
		    break;
	    }

    }

    if (i == N)
	    cout << "NO" << endl;
    else {
	    cout << "YES" << endl;
	    for (i = 0; i < N; i++)
		    printf("%s\n", g[i]);
    }
}
