#include <cstdio>
#include <algorithm>
#include <cmath>

#define EPS 1e-12

using namespace std;

struct PT{
	double x, y;
	PT(){}
	PT(double x, double y) : x(x), y(y) {}
	PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
	PT operator * (double c) const { return PT(x*c, y*c); }
	PT operator / (double c) const { return PT(x/c, y/c); }
};

double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }

bool LinesParallel(PT a, PT b, PT c, PT d){
	return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear( PT a, PT b, PT c, PT d){
	return LinesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d){
	if(LinesCollinear(a, b, c, d)){
		if(dist2(a,c) < EPS || dist2(a,d) < EPS || dist2(b,c) < EPS || dist2(b,d)  < EPS)
			return true;
		if(dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
			return false;
		return true;
	}
	if(cross(d-a, b-a) * cross(c-a, b-a) > 0) 
		return false;
	if(cross(a-c, d-c) * cross(b-c, d-c) > 0)
		return false;
	return true;
}

bool pointInsideRectangle(PT p, PT tl, PT br){
	return p.x >= tl.x && p.x <= br.x && p.y <= tl.y && p.y >= br.y;
}

int main(){
	int T,t, xstart, ystart, xend, yend, xl,yt, xr, yb;
	PT start, end, TL, BR, TR, BL;
	scanf("%d", &T);
	for(t = 0; t < T; t++){
		scanf("%d %d %d %d %d %d %d %d", &xstart, &ystart, &xend, &yend, &xl, &yt, &xr, &yb);
		start = PT(xstart, ystart);
		end = PT(xend, yend);
		TL = PT(min(xl, xr), max(yt, yb));
		TR = PT(max(xl, xr), max(yt, yb));
		BL = PT(min(xl, xr), min(yt, yb));
		BR = PT(max(xl, xr), min(yt, yb));
		printf("%c\n", (pointInsideRectangle(start, TL, BR) || pointInsideRectangle(end, TL, BR) || SegmentsIntersect(start, end, TL, BL) || SegmentsIntersect(start, end, BL, BR) || SegmentsIntersect(start, end, BR, TR) || SegmentsIntersect(start, end, TR, TL)) ? 'T' : 'F');
	}
}

