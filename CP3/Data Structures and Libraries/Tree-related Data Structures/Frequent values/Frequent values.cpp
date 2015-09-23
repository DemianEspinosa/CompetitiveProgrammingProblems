#include <cstdio>
#include <algorithm>

#define MAXN 100005

using namespace std;

int N, Q, a[MAXN], f[MAXN], st[4 * MAXN], x, y, i;

void buildfrequencies(){
	int i, j, k;
	i = 1;
	while (i <= N){
		for(j = i; j < N && a[j] == a[j + 1]; j++);
		
		for(k = i; k <= j; k++)
			f[k] = j - i + 1;
		i = j + 1;
	}
}

void build(int n, int l, int r){
	if(l == r)
		st[n] = f[l];
	else{
		build(2*n, l, (l+r)/2);
		build(2*n+1, (l+r)/2+1, r);
		st[n] = max(st[2*n], st[2*n+1]);
	}
}

void init(){
	buildfrequencies();
	build(1, 1, N);
}

int rmq(int x, int y, int n, int l, int r){
	if(r < x || l > y)
		return -1000000;
	if(l >= x && r <= y)
		return st[n];
	else
		return max(rmq(x, y, 2*n, l, (l+r)/2), rmq(x, y, 2*n+1, (l+r)/2+1, r));
	}

int first(int t){ //indice de primer elemento mayor a t
	int lo, mid, hi;
	lo = 1;
	hi = N;
	mid = (lo + hi)/2;
	while(lo != hi){
		if(a[mid] > t)
			hi = mid;
		else
			lo = mid + 1;
		mid = (lo + hi)/2;
	}
	return mid;
}
int last(int t){ //indice del ultimo elemento menor a t
	int lo, mid, hi;
	lo = 1;
	hi = N;
	mid = (lo + hi)/2;
	while(lo != hi){
		if(a[mid] >= t)
			hi = mid;
		else
			lo = mid + 1;
		mid = (lo + hi) / 2;
	}
	return mid - 1;
}

int query(int x, int y){
	int l = first(a[x]);
	if(l > y)
		l = y + 1;
	int h = last(a[y]);
	if(h < x)
		h = x - 1;
	return max(max(l - x, y - h), rmq(l, h, 1, 1, N));
}

int main(){
	while(scanf("%d", &N), N){
		scanf("%d", &Q);
		for(i = 1; i <= N; i++)
			scanf("%d", &a[i]);
		init();
		for(i = 1; i <= Q; i++){
			scanf("%d %d", &x, &y);
			printf("%d\n", query(x, y));
		}
	}
}


