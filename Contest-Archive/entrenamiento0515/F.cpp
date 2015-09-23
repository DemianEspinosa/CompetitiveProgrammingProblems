#include<cstdio>
#include<cmath>
#include<algorithm>

#define mp make_pair
#define sq(x) ((x)*(x))
#define fst first
#define snd second

using namespace std;

pair<int, int> x, y, z;

pair<pair<double, double>, double> circumcircle(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	if((b.snd - a.snd) * (c.fst - b.fst) == (c.snd - b.snd) * (b.fst - a.fst))
		return mp(mp(0,0), -1);
	double A = 2 * (b.fst - a.fst);
	double B = 2 * (b.snd - a.snd);
	double C = sq(a.fst) + sq(a.snd) - sq(b.fst) - sq(b.snd);
	double D = 2 * (c.fst - a.fst);
	double E = 2 * (c.snd - a.snd);
	double F = sq(a.fst) + sq(a.snd) - sq(c.fst) - sq(c.snd);
	double x = (B * F - C * E)/(A * E - B * D);
	double y = (C * D - A * F)/(A * E - B * D);
	return mp(mp(x,y), sqrt(sq(a.fst - x) + sq(a.snd - y)));
}

int main(){
	scanf("%d %d %d %d %d %d", &x.fst, &x.snd, &y.fst, &y.snd, &z.fst, &z.snd);
	pair<pair<double, double>, double> ans;
	ans = circumcircle(x, y, z);
	if(ans.snd < 0)
		printf("Impossible\n");
	else
		printf("%.6lf %.6lf\n", ans.fst.fst, ans.fst.snd);
	}	


