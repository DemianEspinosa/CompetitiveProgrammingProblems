#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string al = "abcdefghijklmnopqrstuvwxyz", AL = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char s[1005];

int main(){
	int i, j;
	cin.getline(s, 1005);
	for(i = 0; i < al.size(); i++){
		for(j = 0; j < strlen(s); j++)
			if(al[i] == s[j] || AL[i] == s[j])
				break;
		if(j == strlen(s)){
			break;
			}
		}
	printf("%s", i == al.size() ? "pangram\n" : "not pangram");
}
			
