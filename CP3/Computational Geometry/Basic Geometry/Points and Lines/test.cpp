#include <cstdio>
#include <algorithm>
#include <cmath>

#define EPS 1e-12
using namespace std;

struct PT {
	double x, y;
	PT() {}
	PT(double _x, double _y) : x(_x), y(_y){}
	PT(const PT &p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const { return PT(x + p.x, y+p.y);}
	PT operator - (const PT &p) const { return PT(x - p.x, y-p.y);}
	PT operator * (double c) const { return PT(x * c, y * c);}
	PT operator / (double c) const { return PT(x/c, y/c);}
	bool operator < (PT other) const {
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		else
			return y < other.y;
	}
};

PT a[10];

int main(){
	int i, j, N;
	int x, y;
	scanf("%d", &N);
	for ( i = 0; i < N; i++){
		scanf("%d %d", &x, &y);
		a[i] = PT(x, y);
	}

	sort(a, a + N);
	for(i = 0; i < N; i++)
		printf("%lf %lf\n", a[i].x, a[i].y);
}


