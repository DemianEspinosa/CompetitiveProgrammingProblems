#include <cstdio>

using namespace std;

int T, N, c, M, J;

int main(){
	int i, t;
	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		scanf("%d", &N);
		M = 0;
		J = 0;
		for(i = 1; i <= N; i++){
			scanf("%d", &c);
			M += (c/30 + 1) * 10;
			J += (c/60 + 1) * 15;
		}
		if(M < J)
			printf("Case %d: Mile %d\n", t, M);
		else
			if(M == J)
				printf("Case %d: Mile Juice %d\n", t, M);
			else
				printf("Case %d: Juice %d\n", t, J);
	}
}

	
