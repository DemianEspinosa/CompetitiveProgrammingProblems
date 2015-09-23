#include <cstdio>
using namespace std;

int K, a[15];

int main() {
	int i,j,k,l,m,n;
	scanf("%d", &K);
	while(K){
		for(i = 1; i <= K; i++)
			scanf("%d", &a[i]);
		for(i = 1; i <= K - 5; i++)
			for(j = i + 1; j <= K - 4; j++)
				for(k = j + 1; k <= K - 3; k++)
					for(l = k + 1; l <= K - 2; l++)
						for(m = l + 1; m <= K - 1; m++)
							for(n = m + 1; n <= K; n++)
								printf("%d %d %d %d %d %d\n", a[i], a[j], a[k], a[l], a[m], a[n]);
		
		scanf("%d", &K);
		if(K)
			printf("\n");
	}
	
}
