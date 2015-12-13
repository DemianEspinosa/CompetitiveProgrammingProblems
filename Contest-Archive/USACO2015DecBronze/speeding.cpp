#include <fstream>
#include <algorithm>

using namespace std;

int main(){
	int N, M, sp, curr, vlim[105], bessv[105], len, i, j, ans; 
	ifstream in ("speeding.in");
	ofstream out ("speeding.out");

	in >> N >> M;

	for (i = 0, curr = 1; i < N; i++){
		in >> len >> sp;
		for( j = 0; j < len; j++, curr++)
			vlim[curr] = sp;
	}
	for (i = 0, curr = 1; i < M; i++){
		in >> len >> sp;
		for(j = 0; j < len; j++, curr++)
			bessv[curr] = sp;
	}

	for (i = 1; i <= 100; i++){
		ans = max(ans, bessv[i] - vlim[i]);
	}
	
	out << ans << endl;
}
