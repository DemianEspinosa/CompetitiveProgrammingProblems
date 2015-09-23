#include <cstdio>
#include <algorithm>

using namespace std;

int a, b;

int main(){
	scanf("%d %d", &a, &b);
	while(a != -1){
		printf("%d\n",min(b + 100 - a, min(a + 100 - b, a - b >= 0 ? a - b : b - a)));
		scanf("%d %d", &a, &b);
	}
}


