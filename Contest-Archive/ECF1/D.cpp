#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

char g[1005][1005];

int N, M, K, a[1005][1005];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
bool v[1005][1005];

int dfs1(int i, int j){
	if(!v[i][j] || g[i][j] == '*'){
		//printf("Enter first time (%d, %d)\n", i, j);
		v[i][j] = true;
		if(g[i][j] == '*'){
			return 1;
		}
		else{
			int a = 0;
			for(int k = 0; k < 4; k++){
				int r = i + dr[k];
				int c = j + dc[k];
				if(!v[r][c] || g[r][c] == '*')
					a += dfs1(r, c);
				}
			return a;
		}
	}
}

void dfs2(int i, int j, int ans){
	if(!a[i][j] && g[i][j] == '.'){
		a[i][j] = ans;
		dfs2(i + 1, j, ans);
		dfs2(i - 1, j, ans);
		dfs2(i, j + 1, ans);
		dfs2(i, j - 1, ans);
	}
}

int main(){
	FIO
	int i, j, ans;
	scanf("%d %d %d", &N, &M, &K);
	for(i = 0; i < N; i++)
		scanf("%s", g[i]);
	while(K--){
		scanf("%d %d", &i, &j);
		i--;
		j--;
		if(a[i][j])
			printf("%d\n", a[i][j]);
		else{
			ans = dfs1(i, j);
			dfs2(i, j, ans);
			printf("%d\n", a[i][j]);
		}
	}
}


