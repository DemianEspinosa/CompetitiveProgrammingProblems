#include <cstdio>
#include <cmath>

using namespace std;

int S, N, I;

double p, ans, q[1002];

int main(){
	int i;
	scanf("%d", &S);
	while(S--){
		scanf("%d %lf %d", &N, &p, &I);
		q[0] = 1;
		for(i = 1; i <= N; i++)
			q[i] = (1 - p) * q[i - 1];
		printf("%.4lf\n", p > 0 ? (p * q[I - 1])/(1 - q[N]) : 0);
	}
}
