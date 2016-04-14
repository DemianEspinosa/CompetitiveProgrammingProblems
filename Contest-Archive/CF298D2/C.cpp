#include <cstdio>
#include <algorithm>
#include <iostream>

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

long long N, A, d[200005], S;

int main(){
	optimizar_io
	long long i, m, M, pos;
	cin >> N >> A;
	for(i = 1; i <= N; i++){
		cin >> d[i];
		S += d[i];
	}

	for(i = 1; i <= N; i++){
		m = N - 1;
		M = S - d[i];
		pos = min(A - m, d[i]) - max(A - M, 1LL) + 1;
		cout << d[i] - pos << " ";
	}
	cout << "\n";
}
	
	

