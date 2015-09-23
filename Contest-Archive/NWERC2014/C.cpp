#include <cstdio>
#include <algorithm>
#define inf 100000000

using namespace std;

int N, D, p[2005], sum[2005],dp[2005][22];

int R(int x){
	if(x % 10 <= 4)
		return x - (x % 10);
	else
		return x + (10 - x % 10);
}

int main(){
	int i, j, k,n;
	while(scanf("%d %d", &N, &D) != EOF){
		for(i = 1; i <= N; i++)
			scanf("%d", &p[i]);
		for(i = 1; i <= N; i++)
			sum[i] = sum[i - 1] + p[i];
		for(j = 0; j <= D; j++)
			dp[N+1][j] = 0;
		for(i = 1; i <= N; i++)
			dp[i][0] = R(sum[N] - sum[i - 1]);
		for(i = N; i >= 1; i--)
			for(j = 1; j <= D; j++){
				dp[i][j] = inf;
				for(k = i; k <= N; k++)
					dp[i][j] = min(dp[i][j], R(sum[k] - sum[i-1]) + dp[k + 1][j -1]);
			}
		printf("%d\n", dp[1][D]);
	}
}
				
				
		
