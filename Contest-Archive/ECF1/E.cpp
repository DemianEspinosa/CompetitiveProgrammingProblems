#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

bool v[35][35][55];
int dp[35][35][55], N, M, K, T;

int f(int i, int j, int k){
	if(v[i][j][k])
		return dp[i][j][k];
	if(i * j == k || k == 0)
		return 0;
	if(i * j < k)
		return INF;
	
	v[i][j][k] = true;
	dp[i][j][k] = INF;
	
	for(int r = 1; r < i; r++)
		for(int x = 0; x <= k; x++)
			dp[i][j][k] = min(dp[i][j][k], f(r, j, x) + f(i - r, j, k - x) + j * j);
	
	for(int c = 1; c < j; c++)
		for(int x = 0; x <= k; x++)
			dp[i][j][k] = min(dp[i][j][k], f(i, c, x) + f(i, j - c, k - x) + i * i);
	return dp[i][j][k];
}
	

int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &N, &M, &K);
		printf("%d\n", f(N, M, K));
	}
	
}
