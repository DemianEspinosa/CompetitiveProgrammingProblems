#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, C, a[22], b[22], ans, op, curr;

int main(){
	int i, t;
	scanf("%d %d %d", &N, &M, &C);
	t = 1;
	while(N){
		for(i = 1; i <= N; i++){
			scanf("%d", &a[i]);
			b[i] = 0;
		}
		ans = 0;
		curr = 0;
		for(i = 1; i <= M; i++){
			scanf("%d", &op);
			b[op] = (b[op] + 1) % 2;
			if(b[op]){
				curr += a[op];
				ans = max(curr, ans);
			}
			else
				curr -= a[op];
		}
		if(ans > C)
			printf("Sequence %d\nFuse was blown.\n\n", t);
		else
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n", t, ans);
		t++;
		scanf("%d %d %d", &N, &M, &C);
	}
}

			
