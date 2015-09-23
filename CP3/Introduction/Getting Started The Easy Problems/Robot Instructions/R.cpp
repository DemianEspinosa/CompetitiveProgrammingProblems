#include <iostream>
#include <string>

using namespace std;

string str, a[105];

int p, T, N, b[105];

int ins(int x){
	if(a[x] == "LEFT")
		return -1;
	else
		if(a[x] == "RIGHT")
			return 1;
		else{
			return ins(b[x]);
		}
}

int main(){
	int i;
	cin >> T;
	while(T--){
		cin >> N;
		p = 0;
		for(i = 1; i <= N; i++){
			cin >> a[i];
			if(a[i] == "SAME")
				cin >> str >> b[i];
			p += ins(i);
		}
		cout << p << endl;
	}
}
