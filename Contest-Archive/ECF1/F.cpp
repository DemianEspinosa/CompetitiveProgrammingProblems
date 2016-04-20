#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator<(const PT &p) const { return make_pair(x,y) < make_pair(p.x, p.y); }
  bool operator==(const PT &p) const { return make_pair(x,y) == make_pair(p.x, p.y); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double dist(PT p, PT q)   { return sqrt(dist2(p, q)); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

bool segmentLineIntersection(PT a, PT b, PT c, PT d){
	return cross(d-c, a-c)*cross(d-c, b-c) < EPS;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  return a + b*cross(c, d)/cross(b, d);
}

PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}


bool PointInPolygon(vector<PT> &p, PT q){
	bool c = 0;
	for(int i = 0; i < p.size(); i++){
		int j = (i +1) % p.size();
		if(((p[i].y > q.y) != (p[j].y > q.y)) && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y)/(p[j].y - p[i].y))
			c = !c;
	}
return c;
}

bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}


int main() {
	int N, M, i, j, s;
	double x, y, ans;
	PT a, b;
	vector<PT> poli, intersect;
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++){
		scanf("%lf %lf", &x, &y);
		poli.push_back(PT(x, y));
	}
	while(M--){
		intersect.clear();
		ans = 0;
		scanf("%lf %lf", &x, &y);
		a = PT(x, y);
		scanf("%lf %lf", &x, &y);
		b = PT(x, y);
		
		for(i = 0; i < poli.size(); i++){
			j = (i + 1) % poli.size();
			if(!LinesParallel(a, b, poli[i], poli[j]) && segmentLineIntersection(poli[i], poli[j], a, b))
				intersect.push_back(ComputeLineIntersection(poli[i], poli[j], a, b));
		}
		
		sort(intersect.begin(), intersect.end());
		s = intersect.size() - 1;
		for(i = 0; i < s; i++){
			j = i + 1;
			if(PointInPolygon(poli, (intersect[i] + intersect[j])/2) || PointOnPolygon(poli, (intersect[i] + intersect[j])/2))
				ans += dist(intersect[i], intersect[j]);
		}
		printf("%.14lf\n", ans);
		
	}
	
}
