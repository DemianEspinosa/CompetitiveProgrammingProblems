#include <cstdio>
#include <vector>
#include <cmath>

#define EPS 1e-12

using namespace std;

int N;

struct PT {
	int x, y;
	PT() {}
	PT(int x, int y) : x(x), y(y) {}
	PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
};

double dot(PT p, PT q){
	return p.x*q.x + p.y*q.y;
}

double dist2(PT p, PT q){
	return dot(p-q, p-q);
}

double cross(PT p, PT q){
	p.x*q.y - p.y*q.x;
}


bool PointOnPolygon(const vector<PT> &p, PT q){
	int i, j, dy, dx;
	for(i = 0; i < N; i++){
		j = (i + 1) % N;
		dy = p[j].y - p[i].y;
		dx = p[j].x - p[i].x;
		if(dy > 0 && p[i].y <= q.y && q.y <= p[j].y && p[i].x == q.x)
			return true;
		if(dy < 0 && p[j].y <= q.y && q.y <= p[i].y && p[i].x == q.x)
			return true;
		if(dx > 0 && p[i].x <= q.x && q.x <= p[j].x && p[i].y == q.y)
			return true;
		if(dx < 0 && p[j].x <= q.x && q.x <= p[i].x && p[i].y == q.y)
			return true;
	}
		
		return false;
}

bool PointInPolygon(const vector<PT> &p, PT q){
	bool c = 0;
	int  j, dy;
	for(int i = 0; i < N; i++){
		j = (i+1)%N;
	        dy = p[j].y - p[i].y;
		if(dy > 0 && p[i].y <= q.y && q.y < p[j].y && q.x * dy < p[i].x * dy + (p[j].x - p[i].x) * (q.y - p[i].y))
			c = !c;
		if(dy < 0 && p[j].y <= q.y && q.y < p[i].y && q.x * dy > p[i].x * dy + (p[j].x - p[i].x) * (q.y - p[i].y))
			c = !c;
	}
	return c;
}

int main(){
	int i;
	vector<PT> points;
	points.resize(1005);
	PT q;
	while(scanf("%d", &N), N){
		for(i = 0; i < N; i++)
			scanf("%d %d", &points[i].x, &points[i].y);
		scanf("%d %d", &q.x, &q.y);
		printf("%c\n", (PointInPolygon(points, q) || PointOnPolygon(points, q)) ? 'T': 'F');
	}
}

