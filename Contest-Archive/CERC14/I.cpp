#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int T, N, a[100005], r[2], b, w, B, W;
char c[100005];

int main(){
	int i, j;
	scanf("%d", &T);
	while(T--){
		B = W = b = w = 0;
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d %c", &a[i], &c[i]);
			if(c[i] == 'B')
				B += a[i];
			else
				W += a[i];
		}
		if(B == 0){
			cout << W << endl;
			continue;
		}
		if(W==0){
			cout << B << endl;
			continue;
		}

		int g = __gcd(B, W);
		B = B/g;
		W = W/g;
		long long ans = 0;
		for(i = 0; i <= N; i++){
			if(c[i] == 'B'){
				b += a[i];
				if(w>0 && (B*w)%W == 0 && B*w/W <= b){
					ans++;
					b -= w*B/W;
					w = 0;
				}
			}
			else{
				w += a[i];
				if(b>0 && (W*b)%B==0 && W*b/B <= w){
					ans++;
					w -= b*W/B;
					b = 0;
				}
			}
		}

		cout << ans << endl;
	}
}
