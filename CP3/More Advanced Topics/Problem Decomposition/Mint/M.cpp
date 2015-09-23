#include <cstdio>
#include <algorithm>
#include <cmath>
#define inf 100000000
using namespace std;

int N, T, coin[52], table[12], possible[1000000];

int lcm(int a, int b){
	return (a/__gcd(a, b))*b;
	}
int lowReman(int m, int x){
	return x - ((x/m) * m);
	
}

int hiReman(int m, int x){
	return (ceil((double)x/m) * m) - x;
}

int main() {
	
	int i,j,k,l,c,lo[2], hi[2];
	scanf("%d %d", &N, &T);
	while(N){
		for(i = 1; i <= N; i++)
			scanf("%d", &coin[i]);
		for(i = 1; i<= T; i++)
			scanf("%d", &table[i]);
		c = 1;
		for(i = 1; i <= N - 3; i++)
			for(j = i + 1; j <= N - 2; j++)
				for(k = j + 1; k <= N - 1; k++)
					for(l = k + 1; l <= N; l++){
						possible[c] = lcm(coin[i], lcm(coin[j], lcm(coin[k], coin[l])));
						c++;
					}
		
		for(i = 1; i <= T; i++){
			lo[0] = inf;
			hi[0] = inf;
			for(j = 1; j < c; j++){
				if(lowReman(possible[j], table[i]) < lo[0]){
					lo[0] = lowReman(possible[j], table[i]);
					lo[1] = table[i] - lo[0];
				}
				if(hiReman(possible[j], table[i]) < hi[0]){
					hi[0] = hiReman(possible[j], table[i]);
					hi[1] = table[i] + hi[0];
				}
			}
			printf("%d %d\n", lo[1], hi[1]);
		}
		scanf("%d %d", &N, &T);
	}
}
