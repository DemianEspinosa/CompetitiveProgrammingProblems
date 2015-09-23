#include <iostream>
#include <string>

using namespace std;

int T;
string s;

int main() {

	cin >> T;

	for(int i = 0; i < T; i++) {
		cin >> s;		
		
		int k;

		for(int j = 1; j <= s.length(); j++) {
			if(s.length() % j == 0)
				for(k = 0; k < s.length(); k ++) {
					if(s[k] != s[k % j])
						break;
				}
				if(k == s.length()){
					cout << j << endl;
					break;
				}
		}
	}
}
