#include <iostream>
#include <string> 
#include <set> 

using namespace std;

string s;
int N, u[205], d[205], l[205], r[205];
//set<string> st;

int main(){
	int i, j, ans;
	cin >> N >> s;
	for(i = 0; i < s.size(); i++){
		u[i + 1] = u[i];
		d[i + 1] = d[i];
		l[i + 1] = l[i];
		r[i + 1] = r[i];
		if(s[i] == 'U')
			u[i + 1]++;
		if(s[i] == 'D')
			d[i + 1]++;
		if(s[i] == 'L')
			l[i + 1]++;
		if(s[i] == 'R')
			r[i + 1]++;
	}
	for(i = 0, ans = 0; i < s.size() - 1; i++)
		for(j = i + 1; j < s.size(); j++){
			//cout << u[j + 1] - u[i] << " " << d[j+1] - d[i] << " " << l[j+1] - l[i] << " " << r[j+1] - r[i] << endl;
			//cout << s.substr(i, j - i + 1) << endl;
			if(((u[j + 1] - u[i]) == (d[j+1] - d[i])) && ((l[j+1] - l[i]) == (r[j+1] - r[i]))){
				//if(st.count(s.substr(i, j - i + 1)) == 0){
				//	st.insert(s.substr(i, j-i+1));
					ans++;
				//}
			}
		}
	cout << ans << endl;
}


			

