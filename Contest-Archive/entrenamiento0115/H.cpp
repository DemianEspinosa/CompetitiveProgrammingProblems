#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 4587520

using namespace std;

int C, N, O, A, B, X, S, a[MAXN + 5], st[4 * MAXN][2],b[4 * MAXN], n, l, r;
char s[20];

void propagate(int n, int l, int r){
	if(l != r){
		b[2*n] += b[n];
		st[2*n][0] += b[n];
		st[2*n][1] += b[n];
		b[2*n+1] += b[n];
		st[2*n+1][0] += b[n];
		st[2*n+1][1] += b[n];
	}
	b[n] = 0;
}

int rmaxq(int i, int j, int n, int l, int r){
	propagate(n, l, r);
	if(i > r || j < l)
		return 0;
	if(i <= l && j >= r) return st[n][1];
	
	return max(rmaxq(i,j, 2*n, l, (l+r)/2), rmaxq(i,j, 2*n+1, (l+r)/2+ 1, r));
	}

int rminq(int i, int j, int n, int l, int r){
	propagate(n, l, r);
	if(i > r || j < l)
		return N;
	if(i <= l && j >= r) return st[n][0];
	
	return min(rminq(i,j, 2*n, l, (l+r)/2), rminq(i,j, 2*n+1, (l+r)/2 + 1, r));
	}

void update(int i, int j, int x, int n, int l, int r){
	propagate(n, l, r);
	if(r < i || l > j)
		return;
	if(i <= l && r <= j){
		b[n] = x;
		st[n][0] += x;
		st[n][1] += x;
		return;
	}
	update(i, j, x, 2*n, l, (l+r)/2);
	update(i, j, x, 2*n+1, (l+r)/2+1, r);
	st[n][0] = min(st[2*n][0], st[2*n+1][0]);
	st[n][1] = max(st[2*n][1], st[2*n+1][1]);
	}

int groupchange(int A, int B, int X){
	int m = rminq(A, B, 1, 0, C - 1);
	int M = rmaxq(A, B, 1, 0, C - 1);
	if(M + X > N)
		X = N - M;
	if(m + X < 0)
		X = -m;
	
	//printf("A: %d B: %d m: %d M: %d X: %d\n", A, B, m, M, X);
	update(A, B, X, 1, 0, C - 1);
	return X;
	}

int main(){
	scanf("%d %d %d", &C, &N, &O);
	while(O--){
		scanf("%s", s);
		if(strcmp(s, "state") == 0){
			scanf("%d", &X);
			printf("%d\n", rmaxq(X, X, 1, 0, C -1));
		}
		else if(strcmp(s, "groupchange") == 0){
			scanf("%d %d %d", &A, &B, &S);
			printf("%d\n", groupchange(A, B, S));
		}
		else{
			scanf("%d %d", &X, &S);
			printf("%d\n", groupchange(X, X, S));
		}
	}
}

