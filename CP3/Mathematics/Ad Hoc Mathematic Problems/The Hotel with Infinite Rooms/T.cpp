#include <cstdio>

using namespace std;

long long int S, D;

int main(){
	long long int lo, hi, mid;
	while(scanf("%lld %lld", &S, &D) != EOF){
		lo = 0;
		hi = 1000000000;
		mid = (lo + hi)/2;
		while(lo != hi){
			if( S * (mid + 1) + (mid * (mid + 1)) / 2 >= D)
				hi = mid;
			else
				lo = mid + 1;
			mid = (lo + hi)/2;
		}
		printf("%lld\n", S + mid);
	}
}


