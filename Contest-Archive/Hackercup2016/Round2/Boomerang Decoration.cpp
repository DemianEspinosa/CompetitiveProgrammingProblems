#include <cstdio>
#include <algorithm>
#include <iostream>

#define MAXN 100005

using namespace std;

int T, N, A[MAXN], B[MAXN];
char c;
int getTimeJack(int x){
	int i, curr, ans;
	ans = 0;
	for(i = x; i; i--)
		if(A[i] != B[i])
			break;
	if(!i)
		return ans;
	
	for(curr = B[i], ans = 1; i; i--)
		if(B[i] != curr){
			ans++;
			curr = B[i];
		}
	return ans;
}

int getTimeJill(int x){
	int i, curr, ans;
	ans = 0;
	for(i = x; i <= N; i++)
		if(A[i] != B[i])
			break;
	if(i > N)
		return ans;
	
	for(curr = B[i], ans = 1; i <= N; i++)
		if(B[i] != curr){
			ans++;
			curr = B[i];
		}
	return ans;
}

int solve(){
	int lo, mid, hi;
	lo = 0;
	hi = N;
	
	while(hi - lo > 1){
		mid = (lo + hi)/2;
		if(getTimeJack(mid) > getTimeJill(mid + 1))
			hi = mid;
		else if(getTimeJack(mid) < getTimeJill(mid + 1))
			lo = mid;
		else
			return getTimeJack(mid);
		}
	return min(max(getTimeJack(lo), getTimeJill(lo + 1)), max(getTimeJack(lo + 1), getTimeJill(lo + 2)));
}

int main(){
	int i, j, t;
	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		scanf("%d ", &N);
		for(i = 1; i <= N; i++){
			scanf(" %c", &c); 
			A[i] = c - 'A';
		}

		for(i = 1; i <= N; i++){
			scanf(" %c", &c);
			B[i] = c- 'A';
		}

		printf("Case #%d: %d\n", t, solve());
	}
}
