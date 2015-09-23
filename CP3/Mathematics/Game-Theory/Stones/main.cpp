#include <cstdio>

using namespace std;

int N,dp[1002][1002];

int main()
{
    int i,j,k;
    for(i = 0; i <= 1000; i++)
            dp[0][i] = 0;
    for(i = 1; i <= 1000; i++)
        for(j = 1; j <= 1000; j++)
            dp[i][j] = 1;

    for(i = 2; i <= 1000; i++)
        for(j = 1; j < i; j++){
            for(k = 1; 2 * k < i - k && k <= j; k++)
                dp[i][j] = dp[i][j] * dp[i - k][2 * k];
            dp[i][j] = dp[i][j] == 1 ? 0 : 1;
        }
    scanf("%d", &N);
    while(N){
        printf("%s\n", dp[N][N-1] == 1 ? "Alicia" : "Roberto");
        scanf("%d", &N);
    }

}
