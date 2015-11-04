#include <cstdio>
#include <cmath>
#include <vector> 
#include <algorithm>

#define EPS 1e-12

using namespace std;

int N, E, D;

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}

	PT operator + (const PT &p) const{return PT(x + p.x, y + p.y);}
	PT operator - (const PT &p) const{return PT(x - p.x, y - p.y);}
	PT operator * (double c) const{return PT(x*c, y*c);}
	PT operator / (double c) const{return PT(x/c, y/c);}
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
	return fabs(cross(b-a, c- d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d){
	return LinesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d){
	b = b-a;
	d = c-d;
	c = c-a;
	return a + b*cross(c,d)/cross(b,d);
}

pair<vector<PT>, vector<PT> > CutPolygon(const vector<PT> &p, PT r, PT s){
	vector<PT> pleft, pright;
	PT q;
	int i;
	double sidei, sidej;
	for(i = 0; i < p.size(); i++){
		int j = (i+1) % p.size();
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
			//if(!(sqrt(dist2(q, p[i])) < EPS || sqrt(dist2(q, p[j])) < EPS)){
				pleft.push_back(q);
				pright.push_back(q);
			//}
		}
	}
	return make_pair(pleft, pright);
}

double ComputeArea(const vector<PT> &p){
	double area = 0;
	for(int i = 0; i < p.size(); i++){
		int j = (i+1) % p.size();
		area += cross(p[i], p[j]);
	}
	return fabs(area/2.0);
}

int main(){
	int i, j, t = 1;
	double a[1005], b[1005], c[1005], x1, y1, x2, y2;;
	char sign, ineq[1005];
	vector<PT> poli;
	PT point1, point2;
	while(scanf("%d %d %d", &E, &D, &N), E){
		poli.clear();
		for(i = 0; i < N; i++){
			scanf("%lf%*s %c %lf%*s %c %lf", &a[i], &sign, &b[i], &ineq[i], &c[i]);
			if(sign == '-')
				b[i] = -b[i];
		}
		poli.push_back(PT(0, 0));
		poli.push_back(PT(E, 0));
		poli.push_back(PT(E, D));
		poli.push_back(PT(0, D));
		for(i = 0; i < N; i++){
			if(fabs(a[i]) < EPS && fabs(b[i]) < EPS){
				if((ineq[i] == '<' && 0 < c[i]) || (ineq[i] == '>' && 0 > c[i]))
					continue;
				else
					break;
			}
			else if(fabs(b[i]) < EPS){
				point1 = PT(c[i]/a[i], 1);
				point2 = PT(c[i]/a[i], 0);
			}
			else{
				x1 = rand() % 1000000;
				y1 = (c[i] - a[i]*x1)/b[i];
				do{
				x2 = rand() % 1000000;
				} while(x2 == x1);
				y2 = (c[i] - a[i]*x2)/b[i];
				if(x1 > x2){
					swap(x1, x2);
					swap(y1, y2);
				}
				//printf("point1: %lf %lf, point 2: %lf %lf\n", x1, y1, x2, y2);
				point1 = PT(x1, y1);
				point2 = PT(x2, y2);
			}

			if(b[i] < 0)
				ineq[i] = ineq[i] == '<' ? '>' : '<';

			//printf("ineq is: %c\n", ineq[i]);
			if(ineq[i] == '>'){
				//printf("get left cut\n");
				poli = CutPolygon(poli, point1, point2).first;
				}
			else{
				//printf("get right cut\n");
				poli = CutPolygon(poli, point1, point2).second;
			}
			//printf("**\n");
			//for(auto &p: poli)
				//printf("x: %lf, y: %lf \n", p.x, p.y);
		}

		if(i < N)
			printf("Case #%d: 0.00\n", t);
		else
			printf("Case #%d: %.2lf\n", t, ComputeArea(poli));
		t++;
	}
}
