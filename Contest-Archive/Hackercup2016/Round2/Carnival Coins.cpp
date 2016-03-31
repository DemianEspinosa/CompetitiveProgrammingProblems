#include <cstdio>
#include <algorithm>
#define MAXN 3005

using namespace std;

typedef long double DOUBLE;

int T, N, K;

DOUBLE P, g[MAXN][MAXN], prob[MAXN], f[MAXN];

int main(){
	int i, j, t;
	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		scanf("%d %d %Lf", &N, &K, &P);
		
		g[0][0] = 1;
		for(i = 1; i <= N; i++)
			g[i][0] = 0;

		for(j = 1; j <= N; j++)
			g[0][j] = (1 - P) * g[0][j - 1];

		for(j = 1; j <= N; j++)
			for(i = 1; i <= N; i++){
				if(i > j)
					g[i][j] = 0;
				else
					g[i][j] = P * g[i - 1][j - 1]  +  (1 - P)*g[i][j - 1];
			}

		for(i = 0; i <= N; i++)
			prob[i] = 0;

		for(i = K; i <= N; i++)
			for(j = K; j <= i; j++)
				prob[i] += g[j][i];
		
		for(i = 0; i <= N; i++)
			f[i] = 0;
		
		for(i = 1; i <= N; i++)
			for(j = 1; j <= i; j++)
				f[i] = max(f[i], f[i - j] + prob[j]);
			

		printf("Case #%d: %.9Lf\n", t, f[N]);
	}
}
