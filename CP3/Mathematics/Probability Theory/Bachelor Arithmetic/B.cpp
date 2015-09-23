#include <cstdio>

using namespace std;

int B, S;

int main(){
	int t = 1;
	scanf("%d %d", &B, &S);
	while(B){
		if(B == 1)
			printf("Case %d: :-\\\n", t);
		else
			if(B <= S)
				printf("Case %d: :-|\n", t);
			else
				printf("Case %d: :-(\n", t);
		scanf("%d %d", &B, &S);
		t++;
	}
}
