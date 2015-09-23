#include <cstdio>

using namespace std;

int T, N, c[50];

int main(){
	int i;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(i = 1; N; N /= 3, i++)
			c[i] = N % 3;
		for(i--; i; i--)
			printf("%d%c", c[i], i > 1 ? ' ' : '\n');
	}
}
