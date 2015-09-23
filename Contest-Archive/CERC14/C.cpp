#include <cstdio>

using namespace std;

int N, T, a, b;

int main(){
	int i;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(i = 2; i * i <= 2*N; i++){
			if((2 * N) % i == 0){
				if(((2*N)/i + i - 1) % 2 == 0){
					b = ((2*N)/i + i - 1)/2;
					a = ((2*N)/i - i + 1)/2;
					break;
				}
			}
		}
		if(i * i > 2 * N)
			printf("IMPOSSIBLE\n");
		else{
			printf("%d = ", N);
			for(i = a; i <= b; i++)
				printf("%d%s", i, (i < b) ? " + " : "\n");
		}
	}
}

