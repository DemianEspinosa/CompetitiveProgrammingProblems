#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAXN 100005

using namespace std;

long long T, L, N, M, D, W[MAXN];

int main(){
	int i, j, t, ans;
	scanf("%lld", &T);
	for(t = 1; t <= T; t++){
		scanf("%lld %lld %lld %lld", &L, &N, &M, &D);
		for(i = 0; i < N; i++)
			scanf("%lld", &W[i]);
		sort(W, W + N);
		
	}
}
