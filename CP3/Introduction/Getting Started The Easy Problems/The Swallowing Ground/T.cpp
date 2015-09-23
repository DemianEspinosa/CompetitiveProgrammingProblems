#include <cstdio>

using namespace std;

int T, a, b, W, dif;
bool flag;

int main(){
	int i;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &W, &a, &b);
		dif = a - b;
		flag = true;
		for(i = 2; i <= W; i++){
			scanf("%d %d", &a, &b);
			if(a - b != dif)
				flag = false;
		}
		printf("%s\n", flag  ? "yes" : "no");
		if(T >= 1)
			printf("\n");
	}
}
