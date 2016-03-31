#include <cstdio>

#define MAXN 100005

using namespace std;

int T, N, D[MAXN];

int main(){
	int i, j, t, ans, curr;
	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		scanf("%d", &N);
		for(i = 1; i <= N; i++)
			scanf("%d", &D[i]);
		D[N + 1] = 0;
		curr = 1;
		ans = 0;
		for(i = 1; i <= N; i++){
			if(curr == 4)
				curr = 1;
			else if(D[i + 1] <= D[i]){
				ans += 4 - curr;
				curr = 1;
			}
			else if(D[i + 1] - D[i] <= 10){
				curr += 1;
			}
			else if(D[i + 1] - D[i] <= 20 && curr <= 2){
				ans += 1;
				curr += 2;
			}
			else if(D[i + 1] - D[i] <= 20){
				ans += 1;
				curr = 1;
			}
			else if(D[i + 1] - D[i] <= 30 && curr == 1){
				ans += 2;
				curr += 3;
			}
			else{
				ans += 4 - curr;
				curr = 1;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
