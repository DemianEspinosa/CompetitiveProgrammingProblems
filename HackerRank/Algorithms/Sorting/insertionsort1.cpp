#include <cstdio>

using namespace std;

int s, a[1005];

int main(){
	int i, aux, j;
	scanf("%d", &s);
	for(i = 0; i < s; i++)
		scanf("%d", &a[i]);
	aux = a[s - 1];
	for( i = s - 1; aux < a[i - 1]; i--){
		a[i] = a[i - 1];
		for(j = 0; j < s; j++)
			printf("%d%s", a[j], j < (s - 1) ? " " : "\n");
		}
	a[i] = aux;
	for(j = 0; j < s; j++)
		printf("%d%s", a[j], j < (s - 1) ? " " : "\n");
}
