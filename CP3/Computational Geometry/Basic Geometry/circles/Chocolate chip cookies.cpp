#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cmath>
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

vector<PT> circle2PtsRad(PT p, PT q, double r){
	vector<PT> ret;
	PT m = (p + q)/2;
	double d2 = dist2(p, q);
	p = p - q;
	double det = r*r/d2 - .25;
	if(det < 0)
		return ret;
	double h = sqrt(det);
	ret.push_back(PT(m.x + p.y * h, m.y - p.x * h));
	ret.push_back(PT(m.x - p.y * h, m.y + p.x * h));
	return ret;
}

PT points[205];

int main(){
	int T, i, j, k, n, b, ans, count;
	char c;
	vector<PT> centers;
	scanf("%d%*c%*c", &T);
	bool first = true;

	while(T--){
		count = 0;
		ans = 1;
		for (n = 0; !isspace(c = getchar()) && c != EOF; n++){
			ungetc(c, stdin);
			scanf("%lf %lf%*c", &points[n].x, &points[n].y);
		}
		
		for(i = 0; i < n; i++)
			for(j = i + 1; j < n; j++){
				centers = circle2PtsRad(points[i], points[j], 2.5);
				if(centers.size()){
					//printf("i: %d j: %d c1.x: %lf c2.y: %lf\n", i, j, centers[0].x, centers[0].y);
					//printf("i: %d j: %d c1.x: %lf c2.y: %lf\n", i, j, centers[1].x, centers[1].y);
					for(b = 0; b <= 1; b++)
						for(k = 0, count = 0; k < n; k++)
							if(dist2(centers[b], points[k]) - 2.5*2.5 < EPS)
								count++;
				}
				ans = max(ans, count);
			}
		printf("%s%d\n", first ? "" : "\n", ans);
		first = false;
	}
}

