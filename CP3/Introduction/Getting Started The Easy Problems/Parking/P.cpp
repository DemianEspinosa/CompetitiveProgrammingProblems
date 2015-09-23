#include <cstdio>

using namespace std;

int m, M, T, N, a;

int main(){
	int i;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		m = 100;
		M = -1;
		for(i = 1; i <= N; i++){
			scanf("%d", &a);
			if(a < m)
				m = a;
			if(a > M)
				M = a;
		}
		printf("%d\n", 2 * (M - m));
	}
}

		


