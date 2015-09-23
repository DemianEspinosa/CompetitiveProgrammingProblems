#include <cstdio>

using namespace std;

int N, dp[15], fact[12], T;

int main(){
	int i;
	for(fact[0] = 1, i= 1; i <= 12; i++)
		fact[i] = i * fact[i - 1];
	for(dp[2] = 1, i = 3; i <= 12; i++)
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		printf("%d/%d\n", dp[N], fact[N]);
	}
}


