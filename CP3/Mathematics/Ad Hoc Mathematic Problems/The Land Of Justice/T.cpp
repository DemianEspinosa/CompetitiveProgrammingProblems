#include <cstdio>

using namespace std;

long long int N;

int main(){
	scanf("%lld", &N);
	while(N > 0){
		printf("%lld%%\n", N > 1 ? 25 * N : 0); 
		scanf("%lld", &N);
	}
}
