#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define EPS 1e-12

using namespace std;

struct PT{
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT operator + (const PT &p) const {return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const {return PT(x-p.x, y-p.y); }
	PT operator * (double c) const {return PT(x*c, y*c); }
	PT operator / (double c) const {return PT(x/c, y/c); }
	bool operator < (const PT &p) const {return make_pair(x, y) < make_pair(p.x, p.y); }
	bool operator == (const PT &p) const { return make_pair(x, y) == make_pair(p.x, p.y); }
};

double dot(PT p, PT q){	return p.x*q.x + p.y*q.y; }

double dist2(PT p, PT q){ return dot(p-q, p-q); }

double cross(PT p, PT q){ return p.x*q.y - p.y*q.x; }

bool linesParallel(PT a, PT b, PT c, PT d){
	return fabs(cross(b-a, c-d)) < EPS;
}

bool linesCollinear(PT a, PT b, PT c, PT d){
	return linesParallel(a, b, c, c) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}

bool segmentsIntersect(PT a, PT b, PT c, PT d){
	if(linesCollinear(a, b, c, d)){
		if(dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
		if(dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0) return false;
		return true;
	}
	if(cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
	if(cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
	return true;
}

bool segmentLineIntersect(PT a, PT b, PT c, PT d){
	return cross(d - c, a - c) * cross(d - c, b - c) < EPS;
}

PT computeLineIntersection(PT a, PT b, PT c, PT d){
	b = b-a; d = c-d; c = c-a;
	return a + b*cross(c,d)/cross(b,d);
}

PT projectPointSegment(PT a, PT b, PT c){
	double r = dot(b-a, b-a);
	if(fabs(r) < EPS) return a;
	r = dot(c-a, b-a)/r;
	if(r < 0) return a;
	if(r > 1) return b;
	return a + (b-a)*r;
}

double computeSignedArea(vector<PT> &p) {
	double area = 0;
	for(int i = 0; i < p.size(); i++){
		int j = (i+1) % p.size();
		area += cross(p[i], p[j]);
	}
	return area/2.0;
}

double computeArea(vector<PT> &p) {
	return fabs(computeSignedArea(p));
}

bool pointInPolygon(vector<PT> &p, PT q){
	bool c = 0;
	for(int i = 0; i < p.size(); i++){
		int j = (i+1) % p.size();
		if(((p[i].y > q.y) != (p[j].y > q.y)) && q.x < p[i].x + (p[j].x - p[i].x)*(q.y - p[i].y)/(p[j].y - p[i].y))
			c = !c;
	}
	return c;
}

bool pointOnPolygon(vector<PT> &p, PT q){
	for(int i = 0; i < p.size(); i++)
		if(dist2(projectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
			return true;
		return false;
}

vector<PT> computeLinePolygonIntersection(PT a, PT b, vector<PT> &p){
	vector<PT> intersection;
	for(int i = 0; i < p.size(); i++){
		int j = (i+1) % p.size();
		if(!linesParallel(a, b, p[i], p[j]) && segmentLineIntersect(p[i], p[j], a, b))
			intersection.push_back(computeLineIntersection(a, b, p[i], p[j]));
	}
	return intersection;
}

vector<PT> convexPolygonIntersection(vector<PT> &p, vector<PT> &q){
	int i, j, k, l;
	vector<PT> intersection;
	for(i = 0; i < p.size(); i++)
		if(pointInPolygon(q, p[i]) || pointOnPolygon(q, p[i]))
			intersection.push_back(p[i]);
	for(i = 0; i < q.size(); i++)
		if(pointInPolygon(p, q[i]) || pointOnPolygon(p, q[i]))
			intersection.push_back(q[i]);
	for(i = 0; i < p.size(); i++){
		j = (i+1) % p.size();
		for(k = 0; k < q.size(); k++){
			l = (k+1) % q.size();
			if(!linesParallel(p[i], p[j], q[k], q[l]) && segmentsIntersect(p[i], p[j], q[k], q[l]))
				intersection.push_back(computeLineIntersection(p[i], p[j], q[k], q[l]));
		}
	}
	sort(intersection.begin(), intersection.end());
	intersection.erase(unique(intersection.begin(), intersection.end()), intersection.end());

	PT mc = accumulate(intersection.begin(), intersection.end(), PT(0,0)) / intersection.size();

	sort(intersection.begin(), intersection.end(), [&](const PT &a, const PT &b){return atan2((a-mc).y, (a-mc).x) < atan2((b-mc).y, (b-mc).x); } );
	return intersection;
}

int main(){
	int i, j, x, y, N, M, vx, vy, bx, by;
	vector<PT> pts, qts;
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d %d", &x, &y);
			pts.push_back(PT(x, y));
		}
		scanf("%d %d", &vx, &vy);
		scanf("%d", &M);
		for(i = 0; i < M; i++){
			scanf("%d %d", &x, &y);
			qts.push_back(PT(x, y));
		}
		scanf("%d %d", &bx, &by);
		vx -= bx;
		vy -= by;

	}
}
