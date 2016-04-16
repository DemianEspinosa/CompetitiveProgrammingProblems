#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define fst first
#define snd second
#define PI acos(-1.0)
 
using namespace std;
 
int main() {
	optimizar_io
	int n, mini, i;
	long double x, y, minang, ang;
	pair<long double, int> angle[100005];
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> x >> y;
		angle[i].snd = i + 1;
		angle[i].fst = atan2 (y,x);
		if(angle[i].fst < 0)
    			angle[i].fst += 2*PI;
	}
 
	sort(angle, angle + n);
	for(i = 0, minang = 500; i < n; i++){
		ang = abs(angle[i].fst - angle[(i - 1 + n) % n].fst);
		if(min(ang, 2*PI - ang) < minang){
			minang = min(ang, 2*PI - ang);
			mini = i;
		}
	}
    printf ("%d %d\n", angle[(mini - 1 + n) % n].snd, angle[mini].snd);
}
