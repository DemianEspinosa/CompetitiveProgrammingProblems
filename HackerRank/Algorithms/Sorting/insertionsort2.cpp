#include <cstdio>

using namespace std;

int a[1005], N;

void insert(int j){
	int i, aux = a[j];
	for(i = j; aux < a[i - 1]; i--)
		a[i] = a[i - 1];
	a[i] = aux;
}

int main(){
	int k, l;
	scanf("%d", &N);
	for(k = 0; k < N; k++)
		scanf("%d", &a[k]);
	for(k = 1; k < N; k++){
		insert(k);
		for(l = 0; l < N; l++)
			printf("%d%s", a[l], l != N - 1 ? " " : "\n");
		}
}

