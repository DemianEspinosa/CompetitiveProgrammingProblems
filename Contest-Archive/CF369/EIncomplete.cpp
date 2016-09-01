#include <cstdio>
#include <iostream>

using namespace std;

long long N, K;

long long numDos(long long x) {
	long long ans = 0;
	for (long long potdos = 2; x; x = x/potdos) {
		ans += x/potdos;
		potdos *= 2;
	}
	return ans;
}

long long modPow(long long a, long long m, long long n) {
	long long  ans = 1;
	for (; m; m /= 2) {
		if(m % 2)
			ans = ( ans * a ) % n;
			a = ( a * a) % n;
	}
	return ans ;
}

int main() {
	long long i, A, B, P, j, invdos;
	P = 1000003;
	cin >> N >> K;
	
	i = numDos(K - 1);
	B = modPow(2, N, P);
	B = modPow(B, K - 1, P);
	invdos = modPow(2, P -2, P);
	B = (B * modPow(invdos, i, P)) % P;

	if (K > 1000003) {
		A = 0;
		cout << B << " " << B << endl;
	}

	else {
		A = 1;
		long long dosN = modPow(2, N, P);
		for (j = 1; j < K; j++) {
			A = (((dosN - j + P) % P) * A) % P;
		}
		if (A == 0) {
			A = 1;
			B = 1;
		}
		else {
			A = (A * modPow(invdos, i, P)) % P;
			A = (((B - A) % P) + P) % P;
		}
		cout << A << " " << B << endl;
	}
}
