/*
Es fácil ver que es una suma de cuadrados que se calcula con la fórmula descrita en el código
*/
#include <cstdio>

using namespace std;

int N;

int main(){
	scanf("%d", &N);
	while(N){
		printf("%d\n", N * (N + 1) * (2 * N + 1) / 6);
		scanf("%d", &N);
	}
}
