#include <bits/stdc++.h>

#define EPS 1e-12
using namespace std;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

pair<vector<PT>, vector<PT> > CutPolygon(const vector<PT> &p, PT r, PT s){
	vector<PT> pleft, pright;
	PT q;
	int i;
	double sidei, sidej;
	for(i = 0; i < p.size(); i++){
		int j = (i + 1) % p.size();
		sidei = cross(s - r, p[i] - r);
		sidej = cross(s - r, p[j] - r);
		if(fabs(sidei) < EPS){
			pleft.push_back(p[i]);
			pright.push_back(p[i]);
		}
		else if(sidei > 0)
			pleft.push_back(p[i]);
		else
			pright.push_back(p[i]);
		if(sidei*sidej < EPS){
			if(LinesCollinear(r, s, p[i], p[j])) continue;
			q = ComputeLineIntersection(r, s, p[i], p[j]);
			if(!(sqrt(dist2(q, p[i])) < EPS || sqrt(dist2(q, p[j])) < EPS)){
				pleft.push_back(q);
				pright.push_back(q);
			}
		}
	}
	return make_pair(pleft, pright);
}

double ComputeSignedArea(const vector<PT> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area / 2.0;
}

double ComputeArea(const vector<PT> &p) {
  return fabs(ComputeSignedArea(p));
}

vector<PT> square, dice, intersect;
int dots[4] = {1, 3, 6, 4};

int main(){
	int i, j;
	double x, y, ans;
	dice.push_back(PT(-.5, -.5));
	dice.push_back(PT(.5, -.5));
	dice.push_back(PT(.5, .5));
	dice.push_back(PT(-.5, .5));
	while(scanf("%lf %lf", &x, &y) != EOF){
		square.clear();
		square.push_back(PT(x, y));
		for(i = 0; i < 3; i++){
			scanf("%lf %lf", &x, &y);
			square.push_back(PT(x, y));
		}

		ans = 500.0/124;
		for(i = 0; i < 4; i++){
			j = (i + 1) % 4;
			intersect = CutPolygon(square, dice[i], dice[j]).second;
			ans += (ComputeArea(intersect) * 5 * dots[i])/124; 
		}
		printf("%.12lf\n", ans);

	}
}
