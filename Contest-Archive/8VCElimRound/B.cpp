#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, ans;
int N, R, G, B;

bool trye(int x, int y, int z){
	int aux = min(y , z);
	y -= aux;
	z -=aux;
	x += aux;
	if(z > y){
		y = z;
		z = 0;
	}
	if((y % 2 == 0) && x)
		return true;
	else
		return false;
}
	
int main(){
	int i;
	cin >> N >> s;
	for(i = 0; i < s.size(); i++){
		if(s[i] == 'R')
			R++;
		if(s[i] == 'G')
			G++;
		if(s[i] == 'B')
			B++;
	}
	if(trye(B, G, R) || trye(B , G >= 2 ? G - 1: G, R) || trye(B, G, R >= 2 ? R - 1: R))
		ans.push_back('B');
	if(trye(G, B, R) || trye(G , B >= 2 ? B - 1: B, R) || trye(G, B, R >= 2 ? R - 1: R))
		ans.push_back('G');
	if(trye(R, G, B) || trye(R , G >= 2 ? G - 1: G, B) || trye(R, G, B >= 2 ? B - 1: B))
		ans.push_back('R');
	cout << ans << endl;
}



