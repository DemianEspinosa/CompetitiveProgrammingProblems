#include <cstdio>

using namespace std;

int T, M, N, c[10005];

int main(){
	int i, j;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &M, &N);
		for(i = 1; i <= N; i++)
			scanf("%d", &c[i]);
		for(i = 1; i < N; i++)
			for(j = i + 1; j <= N; j++)
				if(c[i] + c[j] == M)
					printf("%d %d\n", i, j);
	}
}

