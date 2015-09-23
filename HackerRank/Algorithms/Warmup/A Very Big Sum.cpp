#include <cstdio>

using namespace std;

long long ans, A, N;

int main(){
	int i;
	scanf("%lld", &N);
	for(i = 1, ans = 0; i <= N; i++){
		scanf("%lld", &A);
		ans += A;
	}
	printf("%lld", ans);
}
	
