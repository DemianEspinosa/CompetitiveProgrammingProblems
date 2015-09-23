#include <cstdio>

using namespace std;

int N, T;

int numberOfFives(int x){
	int k, j;
	for(k = N/3; k >= 0; k--)
		if((N - 3*k) % 5 == 0)
			return 3 * k;
	return -1;
}

int main(){
	int i, j;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		i = numberOfFives(N);
		if(i >= 0){
			for(j = 0; j < i; j++)
				printf("5");
			for(j = 0; j < N - i; j++)
				printf("3");
		}
		else
			printf("-1");
		printf("\n");
	}
}
		
	
			

