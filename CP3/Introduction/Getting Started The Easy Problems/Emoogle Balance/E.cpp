#include <cstdio>

using namespace std;

int N, a;

int main(){
	int ans,i, t;
	scanf("%d", &N);
	t = 1;
	while(N){
		ans = 0;
		for(i = 1; i <= N; i++){
			scanf("%d", &a);
			if(a)
				ans++;
			else
				ans--;
		}
		printf("Case %d: %d\n", t,  ans);
		t++;
		scanf("%d", &N);
	}
}
