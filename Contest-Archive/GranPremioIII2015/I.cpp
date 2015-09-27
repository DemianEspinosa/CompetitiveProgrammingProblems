#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 10000000
using namespace std;

int i, j, p[MAXN];
vector<int> primes;
long long N;

long long phi(long long n){

	long long idx = 0, pf = primes[idx], ans = n;
	while( pf*pf <= n){
		if(n%pf==0)
			ans -= ans/pf;

		while(n%pf==0)
			n/=pf;
	pf = primes[++idx];
	}
	if(n!=1)
		ans -= ans/n;
	return ans;

}

int main(){


	p[0] = p[1] = -1;
	for (i  =2; i < MAXN; i+=2)
		p[i] = 2;
	
	primes.push_back(2);
	for (i = 3; i < MAXN; i+=2){
		if(!p[i]){
			p[i] = i;
			primes.push_back(i);
			if(i <= MAXN/i)
				for(j = i*i; j < MAXN; j+=i)
					if(!p[j])
						p[j] = i;
		}	
	} 


	while(scanf("%lld", &N), N){

	if(N>1)	
			printf("%lld\n", phi(N));
	else
			printf("2\n");
			

	}

	
	
}
