#include<cstdio>

using namespace std;

int T, N;
long long int dp[65];

int main(){
	int i;
	dp[0] = 1;
	for(i = 1; i <= 60; i++)
		if(i % 2)
			dp[i] = 2 * dp[i - 1];
		else
			dp[i] = dp[i - 1] + 1;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}
}



