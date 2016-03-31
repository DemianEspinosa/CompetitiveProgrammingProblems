#include <cstdio> 
#include <cmath>
#include <vector>
#include <algorithm>

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
double cross(PT p, PT q){ return p.x*q.y - p.y*q.x; }

bool pointInTriangle(PT a, PT b, PT c, PT q){
	return cross(b-a, q-a) <= EPS && cross(c-b, q-b) <= EPS && cross(a-c, q-c) <= EPS;
	}
//check if a point is inside or in the boundary of a convex polygon, where the polygon is given CW
bool pointInConvexPolygon(const vector<PT> &p, PT q){
	int lo, hi, mid;
	lo = 0;
	hi = p.size() - 1;
	while(lo + 1 < hi){
		mid = (lo + hi)/2;
		if(cross(p[mid] - p[0], q - p[0]) < 0)
			lo = mid;
		else
			hi = mid;
	}
	return pointInTriangle(p[0], p[lo], p[lo + 1], q);
}

bool polygonInPolygon(vector<PT> &p, vector<PT> &q){
	return all_of(p.begin(), p.end(), [&](PT x){return pointInConvexPolygon(q, x);});
}

bool polygonsIntersect(vector<PT> &p, vector<PT> &q){
	return any_of(p.begin(), p.end(), [&](PT x){return pointInConvexPolygon(q, x);});
}

//void halfConvexPolygonIntersection(vector<PT> &p, vector<PT> &q, vector<PT> &r){
//	for(int i = 0; 

vector<PT> convexPolygonIntersection(vector<PT> &p, vector<PT> &q){
	vector<PT> intersection;

	
	//halfConvexPolygonIntersection(q, p, intersection);
	return intersection;
}

int main(){
	int i, j, x, y, N;
	vector<PT> points;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d %d", &x, &y);
		points.push_back(PT(x, y));
	}
	scanf("%d %d", &x, &y);
	printf("%s\n", pointInConvexPolygon(points, PT(x,y)) ? "Is inside Polygon" : "Is not inside Polygon");
}

	
