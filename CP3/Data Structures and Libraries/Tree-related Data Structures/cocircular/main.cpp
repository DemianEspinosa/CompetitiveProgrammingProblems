#include <cstdio>
#include <algorithm>
#include <map>

#define MAXN 110
#define fst first
#define snd second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef map<pair<pair<pll,pll>,pll>, int> cmap;

cmap circles;
map<ll,int> cnt;

#define simplify(x) if (x.fst * x.snd) {g =  __gcd(abs(x.fst), abs(x.snd)); x.fst /= g; x.snd /= g; } else { x = mp(0,0); }

inline ll sq(ll x) { return x * x; }

int N;
pll p[MAXN];

int main(){
	int i, j, k;
	ll g;

	for (g = 0; g < MAXN; g++)
		cnt[g * (g-1) * (g-2) / 6] = g;

	while (scanf("%d", &N), N){
		int ans = N <= 2 ? N : 2;

		circles.clear();

		for (i = 0; i < N; i++)
			scanf("%lld %lld", &p[i].fst, &p[i].snd);

		for (i = 0; i < N; i++)
			for (j = i+1; j < N; j++)
				for (k = j+1; k < N; k++){
					if ((p[i].fst - p[j].fst)*(p[i].snd - p[k].snd) == (p[i].fst - p[k].fst)*(p[i].snd - p[j].snd)) continue;

					ll A = 2 * (p[j].fst - p[i].fst);
					ll B = 2 * (p[j].snd - p[i].snd);
					ll C = sq(p[i].fst) + sq(p[i].snd) - sq(p[j].fst) - sq(p[j].snd);
					ll D = 2 * (p[k].fst - p[i].fst);
					ll E = 2 * (p[k].snd - p[i].snd);
					ll F = sq(p[i].fst) + sq(p[i].snd) - sq(p[k].fst) - sq(p[k].snd);

					pll cx = mp(B*F - C*E, A*E - B*D);
					pll cy = mp(- (C * cx.snd + A * cx.fst), B * cx.snd);
					pll r2 = mp(sq(cx.snd * cy.snd)
					            - 2 * cx.fst * cx.snd * sq(cy.snd) * p[i].fst
					            + sq(p[i].fst * cx.snd * cy.snd)
						    + sq(cy.fst * cx.snd)
						    - 2 * cy.fst * cy.snd * sq(cx.snd) * p[i].snd
						    + sq(p[i].snd * cx.snd * cy.snd)
					            , sq(cx.snd * cy.snd));

					simplify(cx);
					simplify(cy);
					simplify(r2);

					circles[mp(mp(cx,cy),r2)]++;
				}

		for (cmap::iterator it = circles.begin(); it != circles.end(); it++){
			fprintf(stderr, "%d %d\n", it->second, cnt[it->second]);
			ans = max(ans, cnt[it->second]);
		}

		printf("%d\n", ans);
	}
}
