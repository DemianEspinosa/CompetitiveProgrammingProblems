#include <cstdio>
#include <algorithm> 
#include <vector>
#include <map> 

#define LIM  ((__int128) 1) << 63

using namespace std;

typedef __int128 ll;

ll  primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
vector<ll> num;
map<ll, ll> finv;

void generateCandidates(int d, int x, int y, ll k){
	if(k >= LIM){
		return;
	}
	if(d < 16){
		if(y < x){
			generateCandidates(d, x, y + 1, primes[d]*k);
			generateCandidates(d + 1, y, 0, k);
		}
		else{
			generateCandidates(d + 1, y, 0, k);
		}
	}
	if(d == 16){
		num.push_back(k);
	}
}

ll multinomial(int *exp){
	int i, j, s, l;
	ll ans;
	bool flag;

	for(i = 0, s = 0; i < 16; i++)
		s += exp[i];

	for(i = 1, ans = 1, j = 0, l = 1; i <= s;){
		if(ans < (((__int128) 1) << 75)){
			ans *= i;
			i++;
		}
		else{
			flag = true;
			while(flag && j < 16){
				for(; l <= exp[j]; l++){
					if(ans % l == 0)
						ans /= l;
					
					else
						break;
				}
				if(l > exp[j]){
					l = 1;
					j++;
				}
				else{
					flag = false;
				}
			}


		}
	}

	for(; j < 16; j++){
		for(; l <= exp[j]; l++)
			ans /= l;
		l = 1;
	}
	return ans;
}

void f(){
	int i, j, l, exp[20];
	ll k, n;
	for(i = 1; i < num.size(); i++){
		fill(exp, exp + 16, 0);
		for(j = 0, k = num[i]; j < 16; j++){
			for(; k % primes[j] == 0; k /= primes[j], exp[j]++);
		}

		n = multinomial(exp);

		if(!finv[n]){
			finv[n] = num[i];
		}
	}
}

int main(){
	long long  N;
	generateCandidates(0, 100, 0, 1);
	sort(num.begin(), num.end());
	f();
	while(scanf("%lld", &N) != EOF){
		printf("%lld %lld\n", N, (long long) finv[N]);
	}


}

