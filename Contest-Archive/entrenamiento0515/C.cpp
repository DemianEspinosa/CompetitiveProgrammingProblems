#include<cstdio>

using namespace std;

long long T, N, M;

int main(){
	scanf("%lld", &T);
	while(T--){
		scanf("%lld %lld", &N, &M);
		printf("%lld\n", N * (M - N) + ((N * (N - 1))/2));
	}
}
