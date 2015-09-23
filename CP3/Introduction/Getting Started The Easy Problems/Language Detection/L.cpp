#include <iostream>
#include <string>

using namespace std;

string in;
int t;

int main(){
	t = 1;
	cin >> in;
	while(in != "#"){
		if(in == "HELLO")
			cout << "Case " << t << ": ENGLISH" << endl;
		else
			if(in == "HOLA")
				cout << "Case " << t << ": SPANISH" << endl;
			else
				if(in == "HALLO")
					cout << "Case " << t << ": GERMAN" << endl;
				else
					if(in == "BONJOUR")
						cout << "Case " << t << ": FRENCH" << endl;
					else
						if(in == "CIAO")
							cout << "Case " << t << ": ITALIAN" << endl;
						else
							if(in == "ZDRAVSTVUJTE")
								cout << "Case " << t << ": RUSSIAN" << endl;
							else
								cout << "Case " << t << ": UNKNOWN" << endl;
		cin >> in;
		t++;
	}
}
		
		





		


