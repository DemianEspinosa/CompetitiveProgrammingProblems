#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;

string word;

map<string, int> m1, m2;

int main(){
	while (cin >> N){
		int i, ans = 0;

		m1.clear();
		m2.clear();

		for(i = 1; i <= N; i++, m1[word]++)
			cin >> word;

		for(i = 1; i <= N; i++, m2[word]++)
			cin >> word;
			
		for(auto it = m1.begin(); it != m1.end(); it++)
			ans += min(it -> second, m2[it -> first]);
		
		cout << ans << endl;
	}
}
