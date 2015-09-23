#include <cstdio>

using namespace std;

int N, pos, neg, zero;

int main(){
	int i, a;
	scanf("%d", &N);
	for(i = 1; i <= N; i++){
		scanf("%d", &a);
		if(a < 0)
			neg++;
		else if(a)
			pos++;
		else
			zero++;
	}
	printf("%.3lf\n%.3lf\n%.3lf", 1.0*pos/N, 1.0*neg/N, 1.0*zero/N);
}
