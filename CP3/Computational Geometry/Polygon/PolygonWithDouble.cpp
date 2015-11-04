#include <cstdio>
#include <vector>
#include <cmath>

#define EPS 1e-12

using namespace std;

int N;

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
	PT operator * (double c) const { return PT(x*c, y*c); }
	PT operator / (double c) const { return PT(x/c, y/c); }
};

double dot(PT p, PT q){
	return p.x*q.x + p.y*q.y;
}

double dist2(PT p, PT q){
	return dot(p-q, p-q);
}

double cross(PT p, PT q){
	p.x*q.y - p.y*q.x;
}

PT ProjectPointSegment(PT a, PT b, PT c){
	double r = dot(b-a, b-a);
	if(fabs(r) < EPS) return a;
	r = dot(c-a, b-a)/r;
	if(r < 0) return a;
	if(r > 1) return b;
	return a + (b-a)*r;
}

bool PointOnPolygon(const vector<PT> &p, PT q){
	for(int i = 0; i < N; i++)
		if(dist2(ProjectPointSegment(p[i], p[(i+1)%N], q), q) < EPS)
			return true;
		return false;
}

bool PointInPolygon(const vector<PT> &p, PT q){
	bool c = 0;
	for(int i = 0; i < N; i++){
		int j = (i+1) % N;
		if(((p[i].y > q.y) != (p[j].y > q.y)) && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y)/(p[j].y - p[i].y))
			c = !c;
	}
	return c;
}

int main(){
	int i;
	vector<PT> points;
	points.resize(1005);
	PT q;
	while(scanf("%d", &N), N){
		for(i = 0; i < N; i++)
			scanf("%lf %lf", &points[i].x, &points[i].y);
		scanf("%lf %lf", &q.x, &q.y);
		printf("%c\n", (PointInPolygon(points, q)) ? 'T': 'F');

	}
}
