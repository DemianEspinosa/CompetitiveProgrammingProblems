#include <cstdio>
#include <algorithm>
#include <queue>

#define MAXN 1005
#define sq(x) ((x)*(x))

using namespace std;

int T, x, y, r; 

struct circle{
	int x, y, r;
};

circle c[MAXN];

struct edge{
	int node, next;	
};

int start[MAXN], v[MAXN], color[MAXN], nextEdge;
edge graph[MAXN*MAXN];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void init(){
	nextEdge = 1;
	fill(start, start+MAXN, 0);
	fill(v, v+MAXN, 0);
	fill(color, color+MAXN, 0);
}



int tangent(circle f, circle g){
	return sq(f.r + g.r) == (sq(f.x - g.x) + sq(f.y - g.y));
}

typedef pair<int, int> pii;
queue<pii> q;
#define mp make_pair
void bfs(int u){
	q.push(mp(u, 0));
	
	while(!q.empty()){
		
		pii p = q.front(); q.pop();
		if(v[p.first])
			continue;
		v[p.first]++;

		for(int k = start[p.first]; k; k = graph[k].next){
			if(!v[graph[k].node])
				q.push(mp(graph[k].node, p.second +1));
		}
		
		color[p.first] = p.second%2;

	}
}

int main(){
	int i, j, N;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(i = 0; i < N; i++)
			scanf("%d %d %d", &c[i].x, &c[i].y, &c[i].r);

		init();

		for(i = 0; i < N; i++)
			for(j = i + 1; j < N; j++)
				if(tangent(c[i], c[j])){
					addEdge(i, j);
					addEdge(j, i);
				}

		bfs(0);
		int g, m, n;
		for(i = 0; i < N; i++){
			if(v[i]){
				g = __gcd( c[i].r, c[0].r);
				m = c[0].r/g; n = c[i].r/g;
				if(n == 1)
					printf("%d ", m);
				else
					printf("%d/%d ", m, n);

				printf("%s\n", (!color[i] ? "clockwise" : "counterclockwise"));

			} else
				printf("not moving\n");
		}

	}
}
