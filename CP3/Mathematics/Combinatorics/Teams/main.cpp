#include <cstdio>
#define MOD 1000000007

using namespace std;

long long int N, T;

int main()
{
    long long int i,t,ans,r;
    scanf("%lld", &T);
    for(t = 1; t <= T; t++){
        scanf("%lld", &N);
        ans = N;
        for(i = 1; 30*i <= N - 1; i++)
            ans = (ans * 1073741824) % MOD;
        r = (N -1) - (30 * (i - 1));
        for(i = 1; i <= r; i++)
            ans = (ans * 2) % MOD;


        printf("Case #%lld: %lld\n", t, ans);
    }
}
