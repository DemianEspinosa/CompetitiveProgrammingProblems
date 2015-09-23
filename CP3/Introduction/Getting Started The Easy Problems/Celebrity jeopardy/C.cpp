#include <iostream>
#include <string>

using namespace std;

string str;

int main(){
	while(!getline(cin, str).fail() && str != ""){
		cout << str << endl;
	}
}

