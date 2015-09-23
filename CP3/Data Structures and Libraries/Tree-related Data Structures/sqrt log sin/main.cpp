#include <cstdio>
#include <cmath>
#define MAXN 1000010
#define MOD 1000000
using namespace std;

long long int dp[MAXN] = {1};

int main()
{
    int i;
    for(i = 1; i < MAXN; i++)
        dp[i] = (dp[int(i-sqrt(i))] + dp[int(log(i))] + dp[int(i * pow(sin(i), 2))]) % MOD;
    while(scanf("%d", &i), i != -1)
        printf("%lld\n", dp[i]);

}
