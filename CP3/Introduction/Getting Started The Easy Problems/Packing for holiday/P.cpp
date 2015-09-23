#include <cstdio>

using namespace std;

int L, W, H, T;

int main(){
	int t;
	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		scanf("%d %d %d", &L, &W, &H);
		printf("Case %d: %s\n",t ,L <= 20 && W <= 20 && H <= 20 ? "good" : "bad"); 
	}
}

