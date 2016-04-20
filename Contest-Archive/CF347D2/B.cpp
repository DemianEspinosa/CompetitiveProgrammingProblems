#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

string s, n;
int N, pos, neg, po[105], ne[105];

int num(string x){
	int ans = 0;
	for(int i = 0; i < x.size(); i++)
		ans = 10*ans + (x[i] - '0');
	return ans;
}

int main(){
	int i, j, k, EQ;
	getline(cin, s);
	pos = 1;
	neg = 0;
	for(i = 2; i <= s.size() - 7; i += 4){
		if(s[i] == '+')
			pos++;
		else if(s[i] == '-')
			neg++;
		else
			break;
	}
	EQ = i;
	n = s.substr(EQ + 2, s.size());
	N = num(n);
	if(N < pos - N*neg || N > N*pos - neg)
		printf("Impossible\n");
	else{
		for(i = 0; i < pos; i++)
			po[i] = 1;
		for(i = 0; i < neg; i++)
			ne[i] = 1;
		int curr = pos - neg;

		printf("%d ", po[0]);
		for(k = 4, i = 1, j = 0; k <= EQ - 2; k += 4){
			if(s[k - 2] == '+'){
				i++;
				printf("+ %d ",po[i]); 
			}
			else{
				printf("- %d ",ne[j]); 
				j++;
			}
		}
		printf("= %d\n", N);

	}
}
