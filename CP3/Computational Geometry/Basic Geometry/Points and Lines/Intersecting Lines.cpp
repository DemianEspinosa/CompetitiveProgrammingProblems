#include <cstdio>
#include <cmath>

#define EPS 1e-12

using namespace std;

struct PT{
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
	return p.x*q.y - p.y*q.x;
}

bool LinesParallel(PT a, PT b, PT c, PT d){
	return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollineal(PT a, PT b, PT c, PT d){
	return LinesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d){
	b = b - a;
	d = c - d;
	c = c - a;
	return a + b*cross(c, d)/cross(b, d);
}

int main(){
	int N, x1, y1, x2, y2, x3, y3, x4, y4;
	PT p, q, r, s, z;
	scanf("%d", &N);
	printf("INTERSECTING LINES OUTPUT\n");
	while(N--){
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		p = PT(x1, y1);
		q = PT(x2, y2);
		r = PT(x3, y3);
		s = PT(x4, y4);
		if(LinesParallel(p, q, r, s) && !LinesCollineal(p, q, r, s))
			printf("NONE\n");
		else if(LinesParallel(p, q, r, s) && LinesCollineal(p, q, r, s))
			printf("LINE\n");
		else{
			z = ComputeLineIntersection(p, q, r, s);
			printf("POINT %.2lf %.2lf\n", z.x, z.y);
		}
	}
	printf("END OF OUTPUT\n");
}


