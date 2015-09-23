#include <cstdio>
#include <algorithm>
#include <cstdlib>

#define LIMIT 3000
#define fst first
#define snd second

using namespace std;

typedef pair<long long, long long> pii;

int n, p;
pii P[100100];

int main(){
	int i, j, c;

	scanf("%d %d", &n, &p);

	for (i = 0; i < n; i++)
		scanf("%lld %lld", &P[i].fst, &P[i].snd);

	for (c = 0; c < LIMIT; c++){
		int a, b;

		a = rand() % n;
		do b = rand() % n;
		while (a == b);

		for (i = j = 0; i < n; i++)
			if ((P[i].snd - P[a].snd) * (P[i].fst - P[b].fst) == (P[i].snd - P[b].snd) * (P[i].fst - P[a].fst))
				j++;

		if (j * 100 >= p * n)
			break;
	}

	printf("%s\n", c < LIMIT ? "possible" : "impossible");
}
