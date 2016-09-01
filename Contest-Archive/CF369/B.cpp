#include <cstdio>
#include <iostream>

using namespace std;

int N;
long long int a[505][505], target, i, j, sum, r, c;

int main() {
    bool flag;

    cin >> N;
	  
    for (i = 0; i < N; i++)
	    for (j = 0; j < N; j++)
		    cin >> a[i][j];
    if (N == 1) {
	    cout << 1 << endl;
    }
    else {
    
    for (i = 0; i < N && (target == 0 || !flag); i++) {
	    flag = false;
	    for (sum = 0, j = 0; j < N; j++) {
			sum += a[i][j];
			if (a[i][j] == 0) {
				r = i;
				c = j;
				flag = true;
			}
	    }
	    //cout << "i: " << i << endl;

	    if (!flag && target == 0) {
		    target = sum;
	    }
    }
    //cout << target << endl << r << endl << c << endl;

    for (j = 0, sum  = 0; j < N; j++) {
	    sum += a[r][j];
    }
    a[r][c] = target - sum;
    
    flag = true;
    if (a[r][c] <= 0) {
	    flag = false;
    }

    for(i = 0; i < N; i++) {
	    for (sum = 0, j = 0; j < N; j++) {
		    sum += a[i][j];
	    }
	    if (sum != target) {
		    flag = false;
	    }
    }
    for(j = 0; j < N; j++) {
	    for (sum = 0, i = 0; i < N; i++) {
		    sum += a[i][j];
	    }
	    if (sum != target) {
		    flag = false;
	    }
    }

    for (sum = 0, i = 0; i < N; i++) {
	    sum += a[i][i];
    }
    if (sum != target) {
	    flag = false;
    }

    for (sum = 0, i = 0; i < N; i++) {
	    sum += a[i][N - i - 1];
    }
    if (sum != target) {
	    flag = false;
    }

    if (flag) {
	    cout << a[r][c] << endl;
    }
    else {
	    cout << -1 << endl;
    }
    }
}
