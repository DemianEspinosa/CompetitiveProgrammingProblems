#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define MOD 1000000007

long long choose[3010][3010], N, K, pot10[3010], pot9[3010], ans;
int T, i, j;

int main()
{
    for(i = 0; i < 3001; i++){
        choose[i][0] = choose[i][i] = 1;
        for(j = 1; j < i; j++)
            choose[i][j] = (choose[i-1][j] + choose[i-1][j-1])%MOD;
    }


    pot10[0] = pot9[0] = 1;
    for(i = 1; i < 3001; i++){

        pot10[i] = (pot10[i-1]*10)%MOD;
        pot9[i] = (pot9[i-1]*9)%MOD;

    }
    scanf("%d", &T);

    while(T--){
        ans = 0;
        scanf("%lld %lld", &N, &K);
        if(N%2==0){
            if(N/2 >= K){

                ans = (choose[N/2][K]*pot10[N/2])%MOD;
                ans = (ans*pot9[N/2-K])%MOD;

            }
        } else {
            if(K <= N/2+1){
                ans = (choose[N/2][K-1]*pot10[N/2+1])%MOD;
                ans = (ans*pot9[N/2-K+1])%MOD;
            }
        }

        printf("%lld\n", ans);
    }


}
