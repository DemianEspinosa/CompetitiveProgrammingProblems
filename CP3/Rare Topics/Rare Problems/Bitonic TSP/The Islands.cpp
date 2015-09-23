#include <cstdio>
#include <algorithm>
#include <cmath>

#define fst first
#define snd second
#define MAXN 100

using namespace std;

typedef pair<long long, long long> pii;

int N, B1, B2, R[MAXN];
double dp[MAXN][MAXN];

pii p[MAXN];

double dist(pii p1, pii p2){
	return sqrt((p2.fst - p1.fst) * (p2.fst - p1.fst) + (p2.snd - p1.snd) * (p2.snd - p1.snd));
}

int main(){
	int i, j, v, l, r, t;
	scanf("%d %d %d", &N, &B1, &B2);
	t = 1;
	while(N){
		for (i = 0; i < N; i++)
			scanf("%lld %lld", &p[i].fst, &p[i].snd);
		for(i = N -2; i >= 0; i--)
			for(j = N - 2; j >= 0;j--){
				v = 1 + max(i, j);
				if(v == N - 1)
					dp[i][j] = dist(p[i], p[v]) + dist(p[j], p[v]);
				else 
					if(v != B1 && v != B2)
						dp[i][j] = min(dist(p[i],p[v]) + dp[v][j], dist(p[j], p[v]) + dp[i][v]);
					else
						if(v == B1)
							dp[i][j] = dist(p[i], p[v]) + dp[v][j];
						else
							dp[i][j] = dist(p[j], p[v]) + dp[i][v];
			}

		printf("Case %d: %.2lf\n",t, dp[0][0]);
		printf("0 1");

		
		
		if(dp[1][0] < dp[0][1] || B1 == 1){
			l = 1;
			r = 0;
			for(i = 2; i < N -1; i++)
				if(i == B1)
					printf(" %d", B1);
				else if(dp[i][r] + dist(p[l], p[i]) < dp[l][i] + dist(p[r], p[i]) && i != B2 ){
					printf(" %d", i);
					l = i;
				}
				else{
					R[i] = t;
					r = i;
				}
			R[0] = t;
			R[N - 1] = t;
			for(i = N - 1; i >= 0; i--)
				if(R[i] == t)
					printf(" %d", i);
		}
		else{
			l = 0;
			r = 1;
			for(i = 2; i < N -1; i++)
				if(i == B2)
					printf(" %d", B2);
				else if(dp[i][r] + dist(p[l], p[i]) > dp[l][i] + dist(p[r], p[i]) && i != B1){
					printf(" %d", i);
					r = i;
				}
				else{
					R[i] = t;
					l = i;
				}
			R[0] = t;
			R[N - 1] = t;
			for(i = N - 1; i >= 0; i--)
				if(R[i] == t)
					printf(" %d", i);
		}
		printf("\n");
                scanf("%d %d %d", &N, &B1, &B2);
		t++;
	}
}
