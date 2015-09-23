#include <cstdio>
#include <algorithm>
#include <cstdlib>

#define LIMIT 50
#define fst first 
#define snd second 

using namespace std;

typedef pair<long long, long long> pii;

int a, b, N, P;

pii p[100005];

int main(){
	int i, j, c;
	while(scanf("%d", &N) != EOF){
		scanf("%d", &P);
		for(i = 1; i <= N; i++)
			scanf("%lld %lld", &p[i].fst, &p[i].snd);
		for(i = 1; i <= LIMIT; i++){
			c = 0;
			a = rand() % N + 1;
			do{
				b = rand() % N + 1;
			}while(a == b);

			for(j = 1; j <= N; j++)
				if((p[b].fst - p[j].fst)*(p[j].snd - p[a].snd) == (p[b].snd - p[j].snd)*(p[j].fst - p[a].fst))
					c++;
			if(c * 100 >= P * N)
				break;
		}
		printf("%s\n", i <= LIMIT ? "possible" : "impossible");
	}	
}
			

