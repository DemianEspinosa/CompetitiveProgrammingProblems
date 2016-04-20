#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

string s, ans;
int T;

int main(){
	int t, i;
	FIO
	cin >> T;
	for(t = 1; t <= T; t++){
		ans.clear();
		cin >> s;
		ans.push_back(s[0]);
		for(i = 1; i < s.size(); i++){
			if(s[i] < ans[0])
				ans.push_back(s[i]);
			else
				ans.insert(0, 1, s[i]);
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}
}



