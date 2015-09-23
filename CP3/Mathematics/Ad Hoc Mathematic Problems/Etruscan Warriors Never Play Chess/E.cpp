/*
Son los números de gauss como acumulados. Con una binaria se puede encontrar la fila en la que ya hay lo más que se pueda
*/
#include <cstdio>

using namespace std;

long long int T, N;

int main(){
	long long int i, lo, mid, hi;
	scanf("%lld", &T);
	for(i = 1; i <= T; i++){
		scanf("%lld", &N);
		lo = 1;
		hi = 2000000000;
		mid = (lo + hi)/2;
		while(lo != hi){
			if((mid) * (mid + 1) > 2 * N)
				hi = mid;
			else
				lo = mid + 1;
			mid = (lo + hi)/2;
		}
		printf("%lld\n", mid - 1);
	}
}
