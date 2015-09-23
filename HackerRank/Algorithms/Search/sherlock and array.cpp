#include <cstdio>

using namespace std;

int T, N, s[100005], a[100005];

int main(){
	int i, j;
	scanf("%d", &T);
	while(T--){
		for(i = 1; i <=N; i++)
			s[i] = 0;
		scanf("%d", &N);
		for(i = 1; i <= N; i++)
			scanf("%d", &a[i]);
		for(i = 1; i <= N; i++){
			s[i] = s[i - 1] + a[i];
		}
		for(i = 1; i <= N; i++)
			if(s[N] == s[i] + s[i - 1])
				break;
		printf("%s\n", i <= N ? "YES" : "NO");
	}
}
		
