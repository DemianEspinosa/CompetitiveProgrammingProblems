#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

long long C, N, a[105][5];

string ans(long long c, long long n){
	long long current, i;
	if(a[1][1] != 0 || a[n][2] != 0 || a[n][3] != 0)
		return "impossible";
	for(i = 1, current = 0;  i <= n; i++){
		current -= a[i][1];
		if(current < 0)
			return "impossible";
		if(current + a[i][2] > c)
			return "impossible";
		current += a[i][2];
		if(a[i][3] > 0 && current < c)
			return "impossible";
	}
	if(current != 0)
		return "impossible";
	return "possible";
}

int main(){
	int j;
	scanf("%lld %lld", &C, &N);
	for(j = 1; j <= N; j++)
		scanf("%lld %lld %lld", &a[j][1], &a[j][2], &a[j][3]);
	cout << ans(C, N) << endl;
}
