#include <cstdio>
#include <cmath>
#include <algorithm>
#define MOD 1000000007

using namespace std;

long long N, X, Y, r, s, fact[3000000];

void extendedEuclid(long long a, long long b){
    if(b == 0){
        r = 1;
        s = 0;
        return;
    }
    extendedEuclid(b, a % b);
    long long r1 = s;
    long long s1 = r - (a/b) * s;
    r = r1;
    s = s1;
}

int main(){
    long long den, ans, w, i;
    fact[0] = 1;
    for(i = 1; i < 3000000; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    while (scanf("%lld", &N), N){
        ans = 0;
        scanf("%lld %lld", &X, &Y);
	
	//first factor
        den = (fact[N] * fact[N]) % MOD;
        //printf("den 1 :%lld\n", den);
        extendedEuclid(MOD, den); 
	while(s < 0)
	    s += MOD;
        ans = (ans + ((fact[2*N] * s) % MOD)) % MOD;
        // printf("ans1: %lld\n", ans);
	
	//second factor
        den = (fact[Y] * fact[X + 2]) % MOD;
        //printf("den 21: %lld\n", den);
        extendedEuclid(MOD, den);
        while(s < 0)
	    s += MOD;
        w = (fact[X + 2 + Y] * s) % MOD;
        den = (fact[N - Y] * fact[N - (X + 2)]) % MOD;
        //printf("den 22 : %lld\n", den);
        extendedEuclid(MOD, den);
	while(s < 0)
		s += MOD;
        w = (w * ((fact[2*N - (X + 2 + Y)] * s) % MOD)) % MOD;
        ans = (ans - w) % MOD;
        //printf("ans 2: %lld\n", ans);
	
	//third factor
        den = (fact[Y + 1] * fact[X + 1]) % MOD;
        //printf("den 31: %lld\n", den);
        extendedEuclid(MOD, den);
	while(s < 0)
		s += MOD;
        w = (fact[X + 2 + Y] * s) % MOD;
	//printf("w: %lld\n", w);
        den = (fact[N - (Y + 1)] * fact[N - (X + 1)]) % MOD;
        //printf("den 32: %lld\n", den);
        extendedEuclid(MOD, den);
	while(s < 0)
		s += MOD;
        w = (w * ((fact[2*N - (X + 2 + Y)] * s) % MOD)) % MOD;
	//printf("w: %lld\n", w);
        ans = (ans - w) % MOD;
        //printf("ans 3: %lld\n", ans);

	//fourth factor
        den = (fact[Y + 2] * fact[X]) % MOD;
        //printf("den 41: %lld\n", den);
        extendedEuclid(MOD, den);
	while(s < 0)
		s += MOD;
        w = (fact[X + 2 + Y] * s) % MOD;
        den = (fact[N - (Y + 2)] * fact[N - X]) % MOD;
        //printf("den 42: %lld\n", den);
        extendedEuclid(MOD, den);
	while(s < 0)
		s += MOD;
        w = (w * ((fact[2*N - (X + 2 + Y)] * s) % MOD)) % MOD;
        ans = (ans - w) % MOD;
	while(ans < 0)
		ans += MOD;
        printf("%lld\n", ans);
    }
}
