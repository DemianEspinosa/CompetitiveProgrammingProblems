#include <iostream>
#include <map>

using namespace std;

int n;
string str;
map<string, int> A, B;
int ans = 0;

int main(){
	int i;

	cin >> n;

	for (i = 0; i < n; i++){
		cin >> str;
		A[str]++;
	}

	for (i = 0; i < n; i++){
		cin >> str;
		B[str]++;
	}

	for (auto it = A.begin(); it != A.end(); it++)
		ans += min(it->second, B[it->first]);

	cout << ans << endl;
}
