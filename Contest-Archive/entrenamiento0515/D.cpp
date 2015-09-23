#include<cstdio>
#include<algorithm>

using namespace std;

long long mcm(long long a, long long b){
	return (a/(__gcd(a, b))) * b;
}

long long T, N, D, A, B;

int main(){
	int i;
	scanf("%lld", &T);
	while(T--){
		scanf("%lld %lld %lld", &N, &D, &A);
		A -= D;
		for(i = 2; i <= N; i++){
			scanf("%lld", &B);
			A = mcm(A, B - D);
		}
		printf("%lld\n", A);
	}
}
