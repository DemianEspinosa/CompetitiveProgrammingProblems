#include <cstdio>
#include <iostream>

#define MAXN 100010

using namespace std;

long long T, N, A, B, C[MAXN];

int main(){
	long long i, j, k, t, sum, curr;
	double expected, block;
	scanf("%lld", &T);
	for(t = 1; t <= T; t++){
		scanf("%lld %lld %lld", &N, &A, &B);
		sum = 0;
		expected = 0;
		for(i = 0; i < N; i++){
			scanf("%lld", &C[i]);
			sum += C[i];
		}
		curr = (A/sum) * sum;
		for(j = 0; j < N; j++){
			if(curr + C[j] > A)
				break;
			curr += C[j];
		}
		if(curr + C[j] > B){
			expected = (1.0 * (B + A) * (B - A))/2;
		}
		else{
			expected += ((1.0)*(A - curr) + C[j])*(curr + C[j] - A)/2;
			curr += C[j];
			for(i = 0, block = 0; i < N; i++)
				block += 1.0*C[i]*C[i]/2;
			k = (B - curr)/sum;
			curr += k*sum;
			expected += k*block;
			for(i = (j+1) % N; curr < B; i = (i + 1) % N){
				if(curr + C[i] >= B)
					expected += (1.0 * (B - curr) * (B - curr))/2;
				else
					expected += (1.0 * C[i] * C[i])/2;
				curr += C[i];
			}
		}
		printf("Case #%lld: %.9lf\n", t, expected/(B-A));
	}
}
