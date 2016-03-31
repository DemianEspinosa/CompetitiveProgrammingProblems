#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>

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

double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double dist2(PT p, PT q){ return dot(p-q, p-q); }
double cross(PT p, PT q){ return p.x*q.y - p.y*q.x; }

PT rotateCCW(PT p, double t){
	return PT(p.x*cos(t) - p.y*sin(t), p.x*sin(t) + p.y*cos(t));
}

double ComputeSignedArea(const vector<PT> &p){
	double area = 0;
	for(int i = 0; i < p.size(); i++){
		int j = (i+1) % p.size();
		area += cross(p[i], p[j]);
	}
	return area/2.0;
}

double ComputeArea(const vector<PT> &p){
	return fabs(ComputeSignedArea(p));
}

vector<PT> poli;
int T, C, a;
char c;
double areat = sin(M_PI/3)/2;
PT unit = PT(1, 0);

int main(){
	PT aux, curr;
	cin >> T;
	while(T--){
		cin >> C;
		poli.clear();
		curr = PT(0, 0);
		poli.push_back(curr);
		while(C--){
			aux = unit;
			cin >> c >> a;
			if(c == 'y')
				aux = rotateCCW(aux, M_PI/3);
			else if(c == 'z')
				aux = rotateCCW(aux, (M_PI/3)*2);
			aux = aux * a;
			curr = curr + aux;
			poli.push_back(curr);
		}
		cout << round(ComputeArea(poli)/areat) << endl;
	}
}
			





