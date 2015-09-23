#include <cstdio>

using namespace std;

int N, cat[11];

int main(){
	int i, c = 1;
	cat[0] = 1;
	for(i = 1; i <= 10; i++)
		cat[i] = (cat[i - 1] * 2 * (2 * i - 1))/(i + 1);
	
	while(scanf("%d", &N) != EOF){
		printf("%s%d\n", c == 1 ? "" : "\n", cat[N]);
		c++;
	}
}
