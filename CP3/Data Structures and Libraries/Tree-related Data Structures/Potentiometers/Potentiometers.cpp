#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 200005

using namespace std;

int a[MAXN], N, i, x, y, T, st[4 * MAXN];
char c[5];

int build(int n, int l, int r){
	if(l == r)
		st[n] = a[l];
	else{
		build(2*n, l, (l+r)/2);
		build(2*n+1, (l+r)/2+1, r);
		st[n] = st[2*n] + st[2*n+1];
	}
}

int query(int x, int y, int n, int l, int r){
	if(r < x || l > y)
		return 0;
	if(l >= x && r <= y)
		return st[n];
	else
		return query(x, y, 2*n, l, (l+r)/2) + query(x, y, 2*n+1, (l+r)/2+1, r);
	}

void update(int x, int y, int n, int l, int r){
	if(x < l || x > r)
		return;
	if(l == r){
		a[x] = y;
		st[n] = y;
	}
	else{
		update(x, y, 2*n, l, (l+r)/2);
		update(x,y, 2*n+1, (l+r)/2+1, r);
		st[n] = st[2*n] + st[2*n+1];
	}
}

int main(){
	T = 1;
	while(scanf("%d", &N) && N){
		if(T > 1)
			printf("\n");
		printf("Case %d:\n", T);
		for(i = 1; i <= N; i++)
			scanf("%d", &a[i]);
		build(1, 1, N);
		while(scanf("%s", c) && strcmp(c, "END") != 0){
			scanf("%d %d", &x, &y);
			if(c[0] == 'S')
				update(x, y, 1, 1, N);
			else
				printf("%d\n", query(x, y, 1, 1, N));
		}
		T++;
	}
}
