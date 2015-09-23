#include <cstdio>

using namespace std;

int T, N, dist[105], siz[105],sis[105], D;

int work(int x){
	int current = 0, last = 0,i,flag;
	flag = 1;
	for(i = 0; i <= N + 1; i++)
		sis[i] = siz[i];
	while(flag){
		while(dist[last + 1] - dist[current] <= x && current != N + 1){
		 	if(sis[last + 1] == 2){
		 		current = last + 1;
		 		last = current;
		 		sis[current]--;

		 	}
		 	else{
		 		last++;
		 	}
		 }
		 if(current == last){
		 	flag = 0;
		 }
		 else{
		 	current = last;
		 	sis[current]--;
		 }
	}
	if(current != N + 1){
		return 0;
	}
	else{
		for(i = N; i >= 0; i--){
			if((dist[current] - dist[i] <= x) && (sis[i] >= 1)){
				current = i;
			}
		}
		if(current != 0){
			return 0;
		}
		else{
			return 1;
		}
		
	}
}

int solve(){	 
	int lo, mid, hi;
	lo = 1;
	hi = D;
	mid = (lo + hi) /2;
	while(lo != hi){
		if(work(mid)){
			hi = mid;
		}
			
		else{
			lo = mid + 1;
		}
			
		mid = (lo + hi) /2;
	}
	return mid;
}

int main()
{
    int i,t;
    char S;
    scanf("%d", &T);
    for(t = 1; t <= T; t++){
        scanf("%d %d", &N, &D);
        for(i = 1; i <= N; i++){
        	scanf(" %c-%d ", &S, &dist[i]);
        	if(S == 'B')
        		siz[i] = 2;
        	else
        		siz[i] = 1;
        }
        	
        dist[0] = 0;
        siz[0] = 2;
        dist[N + 1] = D;
        siz[N + 1] = 2;
		
        printf("Case %d: %d\n", t, solve());
        }
}
