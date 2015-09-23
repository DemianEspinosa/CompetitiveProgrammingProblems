#include <cstdio>

using namespace std;

int N, K, P, T;

int main(){
	int t;
	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		scanf("%d %d %d", &N, &K, &P);
		if((K + P) % N == 0)
			printf("Case %d: %d\n",t, N);
		else
			printf("Case %d: %d\n",t, (K + P) % N);
	}
}
