#include<cstdio>

using namespace std;

long long N, T, n;

int main(){
	int i;
	scanf("%lld", &T);
	while(T--){
		scanf("%lld", &N);
		n = N;
		for(i = 0; n; n /= 10)
			if(n % 10)
				if( N % (n % 10) == 0)
					i++;
		printf("%d\n", i);
		}
}
