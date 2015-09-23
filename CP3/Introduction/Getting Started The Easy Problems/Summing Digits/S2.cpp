#include <cstdio>

using namespace std;

int N;

int main(){
	scanf("%d", &N);
	while(N){
		printf("%d\n", N % 9 > 0 ? N % 9 : 9);
		scanf("%d", &N);
	}
}
