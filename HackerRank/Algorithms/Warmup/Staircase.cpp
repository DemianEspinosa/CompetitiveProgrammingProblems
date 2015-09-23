#include <cstdio>

using namespace std;

int N;

int main(){
	int i, j;
	scanf("%d", &N);
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N - i; j++)
			printf(" ");
		for(j = 1; j <= i; j++)
			printf("#");
		printf("\n");
	}
}
