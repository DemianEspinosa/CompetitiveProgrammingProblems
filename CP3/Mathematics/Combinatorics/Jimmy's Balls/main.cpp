#include <cstdio>

using namespace std;

long long int N;

int main()
{
    long long int i,ans,t;
    t = 1;
    scanf("%lld", &N);
    while(N){
        ans = 0;
        for(i = 1; 3 * i < N; i++)
            if(N - i - 1 >= 2 *(i + 1))
                ans += (N - i - 1)/2 - (i + 1) + 1;

        printf("Case %lld: %lld\n", t, ans);
        t++;
        scanf("%lld", &N);
    }

}
