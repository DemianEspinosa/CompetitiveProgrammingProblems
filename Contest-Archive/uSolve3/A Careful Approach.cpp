#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int N, a[10], b[10], ans;

bool trie(int t, int *perm){
	int i;
	int current = a[perm[0]];
	//cout << "trie time gap " << t << "with permutation " << perm[0] << " " << perm[1] << " " << perm[2] << endl;
	//cout << "current : " << current << endl;
	for(i = 1; i < N; i++){
		if(b[perm[i]] >= current + t){
			current = max(current + t, a[perm[i]]);
			//cout << "current : " << current << endl;
		}
		else{
			//cout << "failure at i = " << i << endl;
			break;
		}
	}
	if(i == N){
		//cout << " return true" << endl;
		return true;
	}
	else
		return false;
}

int bin(int *perm){
	int lo = 0;
	int hi = 600 * 1450;
	int mid;
	while(lo < hi){
		mid = (lo + hi + 1)/2;
		if (trie(mid, perm))
			lo = mid;
		else
			hi = mid - 1;
	}
	return hi;
}


int main(){
	int i, t = 1;
	while(scanf("%d", &N), N){
		int perm[] = {0, 1, 2, 3, 4, 5, 6, 7};
		for(i = 0; i < N; i++){
			scanf("%d %d", &a[i], &b[i]);
			a[i] *= 600;
			b[i] *= 600;
		}
		ans = 0;
		
		do{
			ans = max(ans, bin(perm));
			//cout << "ans " << endl;

		}while(next_permutation(perm, perm + N));
		
		int minute = ans/600;
		int seg = (ans - 600*(ans/600) + 5)/10;
		printf("Case %d: %d:%s%d\n", t, minute, seg < 10 ? "0" : "", seg);
		t++;
	}
}
