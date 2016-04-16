#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
 
string s, aux;
int m, l, r, k, n;
 
int main() {
	optimizar_io
 
	cin >> s >> m;
	while(m--){
		cin >> l >> r >> k;
		l--;
		r--;
		n = r - l + 1;
		aux =s.substr(l, n);
		for(int i = 0; i < n; i++)
			s[l + ((i + k) % n)] = aux[i];
	}
	cout << s << "\n";
}
