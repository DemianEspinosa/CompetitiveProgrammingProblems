#include <stdio.h>
#include <stdlib.h>

int T, N, a[13];

int main()
{
    int i, j;
    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        scanf("%d", &N);
        for(j = 1; j <= N; j++)
            scanf("%d", &a[j]);
        printf("Case %d: %d\n", i, a[N/2+1]);

    }
    return 0;
}
