#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>

#define INF 1e15
#define MAXN 110
#define MAXM (110*110)

using namespace std;

double X[MAXN], Y[MAXN], Z[MAXN], R[MAXN];
int N, t;

bool vis[MAXN];
double distan[MAXN];
vector<pair<double, int> > adj[MAXN];
priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;

double sq(double a) {
	return a*a;
}

double dist(int a, int b) {
	return sqrt(sq(X[a]-X[b]) + sq(Y[a] - Y[b]) + sq(Z[a] - Z[b]));
}

void init() {
	for (int i = 0; i < MAXN; i++)
		adj[i].clear();
	fill(vis, vis + MAXN, false);
	fill(distan, distan + MAXN, INF);
}


void dijkstra() {
	while (!q.empty()) {
		pair<double, int> curr = q.top(); q.pop();
		if (vis[curr.second]) continue;
		vis[curr.second] = true;

		distan[curr.second] = curr.first;
		if (curr.second == N+1) break;

		for (auto e : adj[curr.second]) {
			if (!vis[e.second])
				q.push(make_pair(distan[curr.second] + e.first, e.second));
		}
	}
}


int main() {
	while (t++, scanf("%d", &N), N != -1) {
		init();
		for (int i = 0; i < N; i++)
			scanf("%lf %lf %lf %lf", &X[i], &Y[i], &Z[i], &R[i]);
		scanf("%lf %lf %lf", &X[N], &Y[N], &Z[N]); R[N] = 0;
		scanf("%lf %lf %lf", &X[N+1], &Y[N+1], &Z[N+1]); R[N+1] = 0;
		
		for (int i = 0; i <= N; i++)
			for (int j = i + 1; j <= N+1; j++) {
				adj[i].push_back(make_pair(max(dist(i, j) - R[i] - R[j], 0.0), j));
				adj[j].push_back(make_pair(max(dist(i, j) - R[i] - R[j], 0.0), i));
			}

		while (!q.empty()) q.pop();
		q.push(make_pair(0.0, N));
		dijkstra();

		printf("Cheese %d: Travel time = %d sec\n", t, (int)round(10*distan[N + 1]));		
	}
}
