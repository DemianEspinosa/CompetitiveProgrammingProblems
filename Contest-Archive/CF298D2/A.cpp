#include <cstdio>

using namespace std;

int main(){
	int N;
	
	scanf("%d", &N);
	if(N == 1){
		printf("1\n1\n");
	}
	else if(N == 2){
		printf("1\n1\n");
	}
	else if(N == 3){
		printf("2\n1 3\n");
	}
	else if(N == 4){
		printf("4\n2 4 1 3\n");
	}
	else{
		printf("%d\n", N);
		for(int i = 1; i <= N; i += 2)
			printf("%d ", i);
		for(int i = 2; i <= N; i += 2)
			printf("%d ", i);
		printf("\n");
		}
	}
