#include <iostream>
#include <string>

using namespace std;

string op;

int ans, K, T;

int main(){
	cin >> T;
	while(T--){
		cin >> op;
		if(op == "donate"){
			cin >> K;
			ans += K;
		}
		else
			cout << ans << endl;
	}
}

