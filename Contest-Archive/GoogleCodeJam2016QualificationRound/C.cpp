#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int N, J, T;
char s[50];

int main(){
	int t, i, j, k, l, c, m;

	scanf("%d", &T);

	for(t = 1; t <= T; t++){
		printf("Case #%d: \n", t);
		scanf("%d %d", &N, &J);
		c = 1;
		for(i = 1; i < N - 2 && c <= J; i += 2)
			for(j = i + 2; j < N - 2 && c <= J; j += 2)
				for(k = 2; k < N - 1 && c <= J; k += 2)
					for(l = k + 2; l < N - 1 && c <= J; l += 2){
						for(m = 0; m < N; m++)
							s[m] = '0';
						s[0] = '1';
						s[N - 1] = '1';
						s[N - 1 - i] = '1';
						s[N - 1 - j] = '1';
						s[N - 1 - k] = '1';
						s[N - 1 - l] = '1';
						printf("%s 3 2 5 2 7 2 3 2 11\n", s);
						c++;
					}
		}
}

