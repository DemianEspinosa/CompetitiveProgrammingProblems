#include <cstdio>
#include <algorithm>
#define MAXN 1000005
using namespace std;

int T, N, q[MAXN][2], p[MAXN][2], l[2], s[2], dp[MAXN][2];

int main()
{
    int i;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d %d", &N, &l[0], &l[1], &s[0], &s[1]);
        for(i = 1; i < N; i++)
            scanf("%d", &p[i][0]);
        for(i = 1; i < N; i++)
            scanf("%d", &q[i][0]);
         for(i = 1; i < N; i++)
            scanf("%d", &p[i][1]);
        for(i = 1; i < N; i++)
            scanf("%d", &q[i][1]);

        dp[N][0] = s[0];
        dp[N][1] = s[1];
        for(i = N - 1; i >= 1; i--){
            dp[i][0] = min(dp[i+1][0] + q[i][0],dp[i+1][1] + p[i][0]);
            dp[i][1] = min(dp[i+1][1] + q[i][1],dp[i+1][0] + p[i][1]);
        }
        printf("%d\n", min(l[0]+ dp[1][0], l[1]+ dp[1][1]));
    }


    return 0;
}
