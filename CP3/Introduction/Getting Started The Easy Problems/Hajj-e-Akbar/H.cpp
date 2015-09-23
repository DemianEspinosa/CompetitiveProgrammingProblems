#include <iostream>
#include <string>

using namespace std;

string str;

int main(){
	int t = 1;
	cin >> str;
	while(str != "*"){
		if(str == "Hajj")
			cout << "Case " << t << ": Hajj-e-Akbar" << endl;
		else
			cout << "Case " << t << ": Hajj-e-Asghar" << endl;
		cin >> str;
		t++;
	}
}
