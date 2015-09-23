#include <cstdio>

using namespace std;

long long int cat[20], N;

int main(){
	int i;
	cat[0] = 1;
	for(i = 1; i <= 19; i++)
		cat[i] = (2 * (2 * i - 1) * cat[i - 1]) / (i + 1);
	while(scanf("%lld", &N) != EOF){
		for(i = 1; i <= 19; i++)
			if(cat[i] == N)
				printf("%d\n", i);
	}
}
			

