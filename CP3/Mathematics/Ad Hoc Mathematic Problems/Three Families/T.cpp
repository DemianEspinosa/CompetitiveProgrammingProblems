/*
Lo complicado es entender el problema. La tercera familia sólo pagara su parte respectiva del trabajo, no por lo que hicieron ellos
*/
#include <cstdio>

using namespace std;

int X, Y, Z, T;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &X, &Y, &Z);
		printf("%d\n", ((2 * X - Y) * (Z))/(X + Y));
	}
}

