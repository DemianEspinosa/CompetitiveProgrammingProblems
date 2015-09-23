#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define TIMES 10000
#define EPS 1e-8

pair<double,double> minimize(double (*f)(double), double lo, double hi){
	double mid;

	for (int i = 0; i < TIMES; i++){
		mid = (lo + hi) / 2;

		if (f(mid) - f(mid + EPS) > 0)
			lo = mid;
		else
			hi = mid;
	}

	return make_pair(mid, f(mid));
}

double n, p, s, v;

double f(double c){
	return n * pow(log(n) / log(2), c * sqrt(2)) / p / 1e9 + s * (1 + 1 / c) / v;
}

int main(){
	scanf("%lf %lf %lf %lf", &n, &p, &s, &v);
	auto x = minimize(f, 1e-10, 1e30);
	printf("%.8lf %.8lf\n", x.second, x.first);
}
