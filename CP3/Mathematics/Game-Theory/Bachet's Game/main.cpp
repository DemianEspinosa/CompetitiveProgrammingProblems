#include <cstdio>

using namespace std;

int N,M,m[12];

int main()
{
    int i,j, dp[1000005];
    while(scanf("%d", &N) != EOF){
        scanf("%d", &M);
        for(i = 1; i <= M; i++)
            scanf("%d", &m[i]);

        for(i = 0; i <= N; i++){
            dp[i] = 0;
            for(j = 1; j <= M; j++){
                if(i - m[j] >= 0){
                    if(!dp[i - m[j]]){
                        dp[i] = 1;
                    }
                }
            }

        }

        printf("%s\n", dp[N] == 1 ? "Stan wins" : "Ollie wins");
    }

}
