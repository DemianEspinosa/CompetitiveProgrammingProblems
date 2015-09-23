#include <cstdio>
#include <algorithm>

using namespace std;

pair<double,double> pii;

#define MAXN 1010

int N;
double v_walk, v_bike;
pii mapmin, mapmax;
pii start, end;
pii P[MAXN];

double ans;

double sq(double x){
	return x * x;
}

double dist(const pii &a, const pii &b){
	return sqrt(sq(a.fst - b.fst) + sq(a.snd - b.snd));
}

int main(){
	int i, j;

	scanf("%lf %lf", &v_walk, &v_bike);
	scanf("%lf %lf %lf %lf", &mapmin.fst, &mapmin.snd, &mapmax.fst, &mapmax.snd);
	scanf("%lf %lf %lf %lf", &start.fst, &start.snd, &end.fst, &end.snd);

	for (i = 0; i < n; i++)
		scanf("%lf %lf", &P[i].fst, P[i].snd);

	ans = dist(start, end);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			ans = v_walk * dist(start, P[i]) + v_bike * dist(P[i], P[j]) + v_walk * dist(P[j], end);
}
