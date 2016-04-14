#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN (815*815)
#define INF 10101010

int A, B;
int pair_A[MAXN], pair_B[MAXN];
vector<int> adj[2][MAXN];

int queue[MAXN];
int qs, qe, NIL;


#define resetQueue() qs = qe = 0
#define queueNotEmpty (qs < qe)
#define push(x) queue[qe++] = x
#define pop() queue[qs++]
#define mp make_pair
#define fst first
#define snd second

int dist[MAXN];
bool v[2][MAXN];

bool matching_BFS(){
	resetQueue();

	for (int i = 0; i < A; i++){
		if (pair_A[i] == NIL){
			dist[i] = 0;
			push(i);
		} else dist[i] = INF;
	}

	dist[NIL] = INF;

	while (queueNotEmpty){
		int curr = pop();

		if (dist[curr] >= dist[NIL]) continue;

		for (auto x: adj[0][curr]){
			if (dist[pair_B[x]] == INF){
				dist[pair_B[x]] = dist[curr] + 1;
				push(pair_B[x]);
			}
		}
	}

	return dist[NIL] < INF;
}

bool matching_DFS(int x){
	if (x == NIL) return true;

	for (auto y: adj[0][x]){
		if (dist[pair_B[y]] == dist[x] + 1 &&
		    matching_DFS(pair_B[y])){
			pair_B[y] = x;
			pair_A[x] = y;
			return true;
		}
	}

	dist[x] = INF;
	return false;
}

int matching(){
	int size = 0;

	fill(pair_A, pair_A + A + 1, NIL);
	fill(pair_B, pair_B + B + 1, NIL);

	while (matching_BFS())
		for (int i = 0; i < A; i++)
			if (pair_A[i] == NIL && matching_DFS(i))
				size++;

	return size;
}

void dfs(pair<int, int> curr){
	if(!v[curr.fst][curr.snd]){
		//printf("Node %d %d enter dfs\n", curr.fst, curr.snd);
		v[curr.fst][curr.snd] = true;
		if(curr.fst == 1){
			dfs(mp(0, pair_B[curr.snd]));
		}
		else{
			for(auto y: adj[curr.fst][curr.snd])
				dfs(mp(1, y));
		}
	}
}



int R, C, ro[805][805], co[805][805];
char g[805][805];
pair<int, pair<int, int> > row[MAXN], col[MAXN];

int main() {
	while(scanf("%d %d", &R, &C) != EOF){
		for(int i = 0; i < R * C; i++){
			adj[0][i].clear();
			adj[1][i].clear();
			v[0][i] = false;
			v[1][i] = false;
		}
		adj[0][R*C].clear();
		adj[1][R*C].clear();
		
		for (int i = 0; i < R; i++)
			scanf("%s", g[i]);
		
		NIL = R*C;
		
		A = B = 0;
		
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(g[i][j] == '*'){
					if(j == 0 || g[i][j - 1] == '.'){
						row[A].fst = i;
						row[A].snd.fst = j;
					}
					if(j == C - 1 || g[i][j + 1] == '.')
						row[A].snd.snd = j;

					ro[i][j] = A;
					if(j == C - 1)
						A++;
				}
				if(g[i][j] == '.' && j > 0 && g[i][j - 1] == '*')
					A++;
			}
		}
		
		for(int i = 0; i < C; i++){
			for(int j = 0; j < R; j++){
				if(g[j][i] == '*'){
					if(j == 0 || g[j - 1][i] == '.'){
						col[B].fst = i;
						col[B].snd.fst = j;
					}
					if(j == R - 1 || g[j + 1][i] == '.')
						col[B].snd.snd = j;

					co[j][i] = B;
					if(j == R - 1)
						B++;
				}
				if(g[j][i] == '.' && j > 0 && g[j - 1][i] == '*')
					B++;
			}
		}
		
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++){
				if(g[i][j] == '*'){
					adj[0][ro[i][j]].push_back(co[i][j]);
					adj[1][co[i][j]].push_back(ro[i][j]);
				}
			}
	
		int m = matching();
		printf("%d\n", m);
		
		for(int i = 0; i < A; i++)
			if(pair_A[i] == NIL)
				dfs(mp(0, i));
		
		for(int i = 0; i < B; i++)
			if(v[1][i])
				printf("vline %d %d %d\n", col[i].fst + 1, col[i].snd.fst + 1, col[i].snd.snd + 1);
		
		for(int i = 0; i < A; i++)
			if(!v[0][i])
				printf("hline %d %d %d\n", row[i].fst + 1, row[i].snd.fst + 1, row[i].snd.snd + 1);


	}
}
