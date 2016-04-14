#include <cstdio>
#include <algorithm>


using namespace std;

int vi, vf, d, T, dp[105][1100];
bool v[105][1100];

int f(int t, int vold){
	if(v[t][vold] == true)
		return dp[t][vold];
	
	
	if(t == T && (((vold - vf >= 0) ? (vold - vf) : (vf - vold)) <= d))
		return vf;
	if(t == T)
		return -100000;
	v[t][vold] = true;
	
	int i, ans = -100000;
	for(i = max(0, vold - d); i <= vold + d; i++)
		ans = max(ans, f(t + 1, i) + i);
	
	dp[t][vold] = ans;
	return ans;
}



int main(){
	scanf("%d %d %d %d", &vi, &vf, &T, &d);
	printf("%d\n", f(2, vi) + vi); 
}

