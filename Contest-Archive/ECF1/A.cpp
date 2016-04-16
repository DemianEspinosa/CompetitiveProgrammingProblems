#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
 
int main() {
	int t;
	long long n, pot2, ans;
	optimizar_io
	cin >> t;
	while(t--){
		cin >> n;
		for(pot2 = 1, ans = n*(n+1)/2; pot2 <= n; pot2 *= 2)
			ans -= 2*pot2;
		cout << ans << "\n";
	}
 
}
