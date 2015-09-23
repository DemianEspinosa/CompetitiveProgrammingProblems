#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 2010
#define MAXD 22

int n, d;
int p[MAXN];
int dp[MAXN][MAXD][10];
bool v[MAXN][MAXD][10];

int r(int x){
	return x - (x % 10) + 10 * (x % 10 >= 5);
}

int main(){
	int i, j, k;

	scanf("%d %d", &n, &d);

	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for (j = 0; j < MAXD; j++)
		for (k = 0; k < 10; k++)
			dp[n][j][k] = r(k);

	for (i = n-1; i >= 0; i--)
		for (j = 0; j <= d; j++)
			for (k = 0; k < 10; k++)
				dp[i][j][k] = min(
					dp[i+1][j][(k + p[i]) % 10] + k + p[i] - (k + p[i]) % 10,
					!j ? (1<<29) : dp[i+1][j-1][0] + r(k + p[i])
				);

	printf("%d\n", dp[0][d][0]);
}
