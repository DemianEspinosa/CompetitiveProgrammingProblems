#include <cstdio>

using namespace std;

int T, N, K;

int main(){
	int i, a, count;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &K);
		for(i = 0, count = 0; i < N; i++){
			scanf("%d", &a);
			if(a <= 0)
				count++;
			}
		printf("%s", count < K ? "YES\n" : "NO\n");
	}
}

