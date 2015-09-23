#include  <iostream>
#include <string>

using namespace std;

bool posi[12];

string str;

int main(){
	int N, i;
	cin >> N;
	for(i = 1; i <= 10; i++)
		posi[i] = true;
	while(N){
		cin >> str;
		if(str == "too"){
			cin >> str;
			if(str == "high")
				for(i = N; i  <= 10; i++)
					posi[i] = false;
			else
				for(i = N; i >= 1; i--)
					posi[i] = false;
		}
		else{
			cin >> str;
			if(posi[N])
				cout << "Stan may be honest" << endl;
			else
				cout << "Stan is dishonest" << endl;
			for(i = 1; i <= 10; i++)
				posi[i] = true;
		}
		cin >> N;
	}
}
