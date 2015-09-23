#include <cstdio>
#include <cmath>

using namespace std;

int N;

int main(){
	scanf("%d", &N);
	while(N){
		printf("%.0lf\n", floor(log(N)/log(2)));
		scanf("%d", &N);
	}
}

