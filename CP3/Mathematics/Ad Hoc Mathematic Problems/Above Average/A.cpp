/*
Ad-hoc. Se calcula el promedio y se checa cuantos cumplen cumplen
*/
#include <cstdio>

using namespace std;

int C, T, N, g[1005], sum;

double ans;

int main(){
	int i, j;
	scanf("%d", &C);
	while(C--){
		scanf("%d", &N);
		sum = 0;
		for(i = 1; i <= N; i++){
			scanf("%d", &g[i]);
			sum += g[i];
		}
		for(i = 1, j = 0; i <= N; i++)
			if(g[i] * N > sum)
				j++;
		ans = ((double)(100 * j))/N;
		printf("%.3lf%%\n", ans);
	}
}
		

