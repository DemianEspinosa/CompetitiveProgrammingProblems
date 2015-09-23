#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 10010
#define MAXE MAXN

struct edge {
	int node, next;
};

edge graph[MAXE*2];
int nextEdge = 1, start[MAXN];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int N;
int NIC[MAXN][2];
int nextf = 1;

int f(int node, int parent, int pf){
	NIC[node][0] = pf;
	NIC[node][1] = graph[start[node]].next || node == 1 ? nextf++ : 0;

	bool first = true;
	for (int i = start[node]; i; i = graph[i].next){
		if (graph[i].node == parent) continue;
		f(graph[i].node, node, NIC[node][first]);
		first = false;
	}
}

int main(){
	int i;

	scanf("%d", &N);

	for (i = 1; i < N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(a, b);
		addEdge(b, a);
	}

	f(1, -1, 0);

	for (i = 1; i <= N; i++)
		printf("%d %d\n", NIC[i][0], NIC[i][1]);
}
