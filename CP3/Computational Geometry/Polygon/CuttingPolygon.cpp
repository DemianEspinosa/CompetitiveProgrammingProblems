#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define EPS 1e-12

using namespace std;

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT operator + (const PT &p) const{ return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const{ return PT(x - p.x, y - p.y); }
	PT operator * (double c) const{ return PT(x*c, y*c); }
	PT operator / (double c) const{ return PT(x/c, y/c); }
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

PT ComputeLineIntersection(PT a, PT b, PT c, PT d){
	b = b-a;
	d = c-d;
	c = c-a;
	return a + b*cross(c, d)/cross(b,d);
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
			q = ComputeLineIntersection(r, s, p[i], p[j]);
			if(!(sqrt(dist2(q, p[i])) < EPS || sqrt(dist2(q, p[j])) < EPS)){
				pleft.push_back(q);
				pright.push_back(q);
			}
		}
	}
	return make_pair(pleft, pright);
}

int main(){
	int T, N, i;
	double x, y, a, b, c, d;
	vector<PT> poli;
	pair<vector<PT>, vector<PT> > cutpoli;
	scanf("%d", &T);
	while(T--){
		poli.clear();
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%lf %lf", &x, &y);
			poli.push_back(PT(x, y));
		}
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		cutpoli = CutPolygon(poli, PT(a, b), PT(c,d));
		printf("Left side of the polygon:");
		for(i = 0; i < cutpoli.first.size(); i++)
			printf("p[%d]: %lf %lf ", i, cutpoli.first[i].x, cutpoli.first[i].y);
		printf("\n");
		printf("Right side of the polygon:");
		for(i = 0; i < cutpoli.second.size(); i++)
			printf("p[%d]: %lf %lf ", i, cutpoli.second[i].x, cutpoli.second[i].y);
		printf("\n");
	}
}




