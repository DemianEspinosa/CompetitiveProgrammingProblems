#include <cstdio>

#define MAXN 100005

using namespace std;

long long T, N, P, B[MAXN], sum[MAXN], dp[MAXN];

int find(int x){
	int lo, hi, mid;
	if(B[x] > P)
		return x + 1;
	hi = x;
	lo = 1;
	while(lo != hi){
		mid = (lo + hi)/2;
		if(sum[x] - sum[mid - 1] > P)
			lo = mid + 1;
		else
			hi = mid;
	}
	return hi;
}

int main(){
	int i, j, t;
	scanf("%lld", &T);
	for(t = 1; t <= T; t++){
		scanf("%lld %lld", &N, &P);
		for(i = 1; i <= N; i++)
			scanf("%lld", &B[i]);
		for(i = 1; i <= N; i++)
			sum[i] = sum[i-1] + B[i];
		for(i = 1; i <= N; i++)
			dp[i] = dp[i-1] + i - find(i) + 1;
		
		printf("Case #%d: %lld\n", t, dp[N]);
	}
}
