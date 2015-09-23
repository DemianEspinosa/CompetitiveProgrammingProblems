#include <cstdio>

using namespace std;

int N;

int sumdig(int x){
	int ans = 0;
	while(x){
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main(){
	scanf("%d", &N);
	while(N){
		while(N >= 10)
			N = sumdig(N);
		printf("%d\n", N);
		scanf("%d", &N);
	}
}
