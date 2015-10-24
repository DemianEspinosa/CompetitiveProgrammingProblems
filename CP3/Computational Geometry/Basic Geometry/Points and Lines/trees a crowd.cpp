#include <cstdio>

#define MAXN 5005
#define sq(x) ((x)*(x))

using namespace std;

struct PT{
	double x, y, z;
};

PT p[MAXN];
int hist[15];

int main(){
	int i, j, h, N, flag;
	N = 0;
	while(scanf("%lf %lf %lf", &p[N].x, &p[N].y, &p[N].z), p[N].x + p[N].y + p[N].z > 0){
		N++;
	}
	for(i = 0; i < N; i++){
		flag = 1;
		for(h = 1; h <= 10 && flag; h++)
			for(j = 0; j < N; j++)
				if(i != j && sq(p[i].x - p[j].x) + sq(p[i].y - p[j].y) + sq(p[i].z - p[j].z) < sq(h)){
					flag = 0;
					hist[h-1]++;
					break;
				}
			}
	for(h = 0; h < 10; h++)
		printf("%4d", hist[h]);
}



		
