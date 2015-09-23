#include <cstdio>

using namespace std;

int N, dp[80];

int main()
{
    int i;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    for(i = 4; i <= 76; i++)
        dp[i] = dp[i-2] + dp[i-3];
    while(scanf("%d", &N) != EOF)
        printf("%d\n", dp[N]);
}
