#include <fstream>
#include <algorithm>

using namespace std;

int N, M, D, S, milk[55][55], sick[55];

int main(){
	ifstream in ("badmilk.in");
	ofstream out ("badmilk.out");
	int i, j, p, m, t, ans, count;
	in >> N >> M >> D >> S;

	ans = 0;
	for(i = 1; i <= M; i++)
		for(j = 1; j <= N; j++)
			milk[i][j] = 105;

	for(i = 0; i < D; i++){
		in >> p >> m >> t;
		milk[m][p] = min(milk[m][p], t);
	}

	for(i = 0; i < S; i++){
		in >> p >> t;
		sick[p] = t;
	}

	for(i = 1; i <= M; i++){
		for(j = 1, count = 0; j <= N; j++){
			if(milk[i][j] <= 100)
				count++;
			if(sick[j] && sick[j] <= milk[i][j])
				break;
		}
		if(j > N)
			ans = max(ans, count);
		}
	out << ans << endl;
}
