#include <cstdio>

using namespace std;

int T, a, b;

int main(){
	int i, t;
	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", t, ((b + 1)/2) * ((b + 1)/2) - (a / 2) * (a / 2));
		}
	}
	
