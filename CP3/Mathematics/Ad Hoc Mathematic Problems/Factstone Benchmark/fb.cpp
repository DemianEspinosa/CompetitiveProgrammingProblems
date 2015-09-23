#include <cstdio>
#include <cmath>

using namespace std;

int Y;

int main(){
	int i, n, m, lo, mid, hi;
	double bot[300000], top;
	scanf("%d", &Y);
	while(Y){
		n = (Y-1960)/10;
		n += 2;
		top = pow(2, n) * log(2);
		lo = 1;
		hi = 300000;
		bot[0] = 0;
		for(i = 1; i <= hi; i++)
			bot[i] = bot[i - 1] + log(i);
		while(lo != hi){
			mid = (lo + hi) / 2;
			if(bot[mid] > top)
				hi = mid;
			else
				lo = mid + 1;
		}
		mid = (lo + hi)/2;
		printf("%d\n", mid - 1);
		scanf("%d", &Y);
	}
}

