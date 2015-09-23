#include <cstdio>

using namespace std;

int A[105][105], N;

int main(){
	int i, j, ans;
	scanf("%d", &N);
	for(i = 1; i <= N; i++)
		for(j = 1; j <= N; j++)
			scanf("%d", &A[i][j]);
	for(i = 1, ans = 0; i <= N; i++)
		ans = ans + A[i][i] - A[i][N - i + 1];
	if(ans < 0)
		ans = -ans;
	printf("%d", ans);
}
