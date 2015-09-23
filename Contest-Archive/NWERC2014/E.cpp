#include <cstdio>
#include <algorithm>
#include <cmath>

#define TIMES 1000
#define EPS 1e-8

using namespace std;

typedef pair<double, double> pii;

double n, p, s, v;

pii ans;

double f(double c){
	return (n * pow(log(n)/log(2), sqrt(2) * c))/(p * 1e9) + (s*(1 + 1/c))/v;

}
pii solve(){
	double lo, mid, hi;
	lo = 1e-10;
	hi = 1e30;
	
	for(int i = 0; i < TIMES; i++){
		mid = (lo + hi)/2;

		if(f(mid + EPS) - f(mid) < 0)
			lo = mid;

		else
			hi = mid;
	}
	return make_pair(mid, f(mid));
}

int main(){
	while(scanf("%lf %lf %lf %lf ", &n, &p, &s, &v) != EOF){
		ans = solve();
		printf("%.8lf %.8lf\n", ans.second, ans.first); 
	}
}

