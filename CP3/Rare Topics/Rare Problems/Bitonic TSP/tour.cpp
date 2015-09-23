#include <cstdio>
#include <algorithm>
#include <cmath>

#define fst first
#define snd second
#define MAXN 1000

using namespace std;

typedef pair<long long, long long> pii;

int N;
double dp[MAXN][MAXN];

pii p[MAXN];

double dist(pii p1, pii p2){
	return sqrt((p2.fst - p1.fst) * (p2.fst - p1.fst) + (p2.snd - p1.snd) * (p2.snd - p1.snd));
}

int main(){
	int i, j, v;
	while(scanf("%d", &N) != EOF){
		for (i = 0; i < N; i++)
			scanf("%lld %lld", &p[i].fst, &p[i].snd);
		for(i = N -2; i >= 0; i--)
			for(j = N - 2; j >= 0;j--){
				v = 1 + max(i, j);
				if(v == N - 1)
					dp[i][j] = dist(p[i], p[v]) + dist(p[j], p[v]);
				else
					dp[i][j] = min(dist(p[i],p[v]) + dp[v][j], dist(p[j], p[v]) + dp[i][v]);
			}
		printf("%.2lf\n", dp[0][0]);
	}
}
