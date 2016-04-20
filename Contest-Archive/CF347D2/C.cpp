#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

long long T, lim[9] = {1989, 1999, 2099, 3099, 13099, 113099, 1113099, 11113099, 111113099};
string s, N;

long long num(string x){
	int ans = 0;
	for(int i = 0; i < x.size(); i++){
		ans = 10*ans + (x[i] - '0');
	}
	return ans;
}


int main(){
	int i, j;
	cin >> T;
	while(T--){
		cin >> s;
		N = s.substr(4, s.size());
		j = N.size();
		if(j == 1)
			cout << 1989 + (N != "9" ? num(N) + 1 : 0) << "\n";
		else if(j == 2){
			cout << 1999 + (N != "99" ? num(N) + 1 : 0) << "\n";
		}
		else if(j == 3){
			if(num(N) < 99)
				cout << "3" << N << "\n";
			else
				cout << "2" << N << "\n";
		}
		else{
			if(num(N) < lim[j - 1])
				cout << "1" << N << "\n";
			else
				cout << N << "\n";
		}
	}
}

