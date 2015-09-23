#include<cstdio>
#include<algorithm>

using namespace std;

int K, T, front[105], side[105];

int maxim(){
	int i, j, ans;
	ans = 0;
	for(i = 1; i <= K; i++)
		for(j = 1; j <= K; j++)
			ans += min(side[i], front[j]);
	return ans;
}

int minim(){
	int i, j, ans = 0;
	
	for(i = 1; i <= K; i++)
		for(j = 1; j <= K; j++)
			if(front[i] == side[j]){
				side[j] = 0;
				break;
			}

	for(i = 1; i <= K; i++)
		ans += side[i] + front[i];
	return ans;
}

int main(){
	int i;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &K);
		for(i = 1; i <= K; i++)
			scanf("%d", &front[i]);
		for(i = 1; i <= K; i++)
			scanf("%d", &side[i]);
		printf("Minimalni budova obsahuje %d kostek, maximalni %d kostek.\n", minim(), maxim());
	}
}
	
