#include <cstdio>
#include <algorithm>

using namespace std;

long long T, N, n;

bool check(bool *dig){
	int i;
	for(i = 0; i < 10; i++){
		if(!dig[i])
			break;
	}
	return i == 10;
}

int main(){
	long long i, t;
	bool dig[10];

	scanf("%lld", &T);
	
	for(t = 1; t <= T; t++){
		fill(dig, dig + 10, false);
		scanf("%lld", &N);
		if(N){
			for(i = N; !check(dig); i += N){
				for(n = i; n; n /= 10)
					dig[n % 10] = true;
			}
			printf("Case #%lld: %lld\n", t, i - N);
		}
		else{
			printf("Case #%lld: INSOMNIA\n", t); 
		}
	}
}



