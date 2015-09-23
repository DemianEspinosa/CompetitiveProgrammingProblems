#include <cstdio>

using namespace std;

long long int N, F, Y, B, E, ans;

int main(){
	scanf("%lld", &N);
	while(N--){
		scanf("%lld", &F);
		ans = 0;
		while(F--){
			scanf("%lld %lld %lld", &Y, &B, &E);
			ans += Y * E;
		}
		printf("%lld\n", ans);
	}
}
