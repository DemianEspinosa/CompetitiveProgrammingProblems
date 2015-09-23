#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

string s, r;
int T;
int main(){
	int i, N;
	cin >> T;
	while(T--){
		cin >> s;
		N = s.size();
		for(i = 1; i < N; i++)
			if(abs(s[i] - s[i - 1]) != abs(s[N - i - 1] - s[N - i]))
				break;
		printf("%s", i == N ? "Funny\n" : "Not Funny\n");
	}
}
