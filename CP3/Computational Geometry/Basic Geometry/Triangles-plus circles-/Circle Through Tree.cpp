#include <cstdio>
#include <cmath>

#define EPS 1e-12

using namespace std;

struct PT{
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT operator + (const PT &p) const {return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const {return PT(x - p.x, y - p.y); }
	PT operator * (double c) const {return PT(x*c, y*c); }
	PT operator / (double c) const {return PT(x/c, y/c); }
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

PT RotateCW90(PT p){
	return PT(p.y, -p.x);
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d){
	b = b-a;
	d = c-d;
	c = c-a;
	return a + b*cross(c, d)/cross(b, d);
}

PT ComputeCircleCenter(PT a, PT b, PT c){
	b = (a + b)/2;
	c = (a + c)/2;
	return ComputeLineIntersection(b, b + RotateCW90(a - b), c, c + RotateCW90(a - c));
}

int main(){
	double x1, y1, x2, y2, x3, y3, r2;
	PT c;
	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6){
		c = ComputeCircleCenter(PT(x1, y1), PT(x2, y2), PT(x3, y3));
		r2 = dist2(c, PT(x1, y1));
		if(fabs(c.x) > EPS)
			printf("(x %c %.3lf)^2 + ", (c.x > -EPS) ? '-':'+', fabs(c.x));
		else
			printf("x^2 + ");
		if(fabs(c.y) > EPS)
			printf("(y %c %.3lf)^2 = ", (c.y > -EPS) ? '-':'+', fabs(c.y));
		else
			printf("y^2 = ");
		printf("%.3lf^2\n", sqrt(r2));
		printf("x^2 + y^2 ");
		if(fabs(c.x) > EPS)
			printf("%c %.3lfx ", (c.x > -EPS) ? '-':'+', 2*fabs(c.x));
		if(fabs(c.y) > EPS)
			printf("%c %.3lfy ", (c.y > -EPS) ? '-':'+', 2*fabs(c.y));
		printf("%c %.3lf ", (c.x*c.x + c.y*c.y - r2 > -EPS) ? '+':'-', fabs(c.x*c.x + c.y*c.y - r2));
		printf("= 0\n");
		printf("\n");
	}
}

		


