#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s;
int N, K;

int main(){
	int i;
	cin >> N >> s >> K;
	K = K % 26;
	for(i = 0; i < N; i++)
		if(isalpha(s[i]))
			if(isupper(s[i]) && s[i] + K - 'Z' <= 0 || islower(s[i]) && s[i] + K - 'z' <= 0)
				s[i] = s[i] + K;
			else
				s[i] = s[i] + K - 26;
	cout << s;
	}
			
