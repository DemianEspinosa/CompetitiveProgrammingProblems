#include <cstdio>
#include <queue>
#define MAXN 1005
#define MAXM 1000005


using namespace std;

typedef struct{
	int node, next;
}edge;

int start[MAXN];
edge graph[2*MAXM];
int nextEdge = 1;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int visited[MAXN], T, N, M, S;

queue<int> st;

int main(){
	int i, e1,e2, dist[MAXN], c;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		for(i = 1; i <= N; i++){
			start[i] = 0;
			dist[i] = 0;
		}
		nextEdge = 1;
		
		for(i = 1; i <= N; i++)
			visited[i] = 0;

		for(i = 1; i <= M; i++){
			scanf("%d %d", &e1, &e2);
			addEdge(e1, e2);
			addEdge(e2, e1);
		}
		scanf("%d", &S);

		st.push(S);
		visited[S] = 1;
		while(!st.empty()){
			c = st.front();
			st.pop();

			for(i = start[c]; i; i = graph[i].next){
				if(!visited[graph[i].node]){
					st.push(graph[i].node);
					dist[graph[i].node] = dist[c] + 6;
					visited[graph[i].node] = 1;
				}
			}
		}
		for(i = 1; i <= N; i++)
			if(i != S)
				printf("%d ", dist[i] > 0 ? dist[i] : -1);
		printf("\n");
		}
}
