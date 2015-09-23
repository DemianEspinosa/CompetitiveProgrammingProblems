#include <cstdio>
#include <algorithm>

using namespace std;

int N, D, R, m[105], e[105];

int main()
{
    int i,ans;
    scanf("%d%d%d", &N, &D, &R);
    while(N){
        ans = 0;
        for(i = 0; i < N; i++)
            scanf("%d", &m[i]);

        for(i = 0; i < N; i++)
            scanf("%d", &e[i]);

        sort(m, m + N);
        sort(e, e + N);

        for(i = 0; i < N; i++)
            if(D < m[i] + e[N - i - 1])
                ans += R * (m[i] + e[N - i - 1] - D);
        printf("%d\n", ans);
        scanf("%d%d%d", &N, &D, &R);
    }
}
