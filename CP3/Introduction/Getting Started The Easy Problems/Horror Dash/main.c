#include <stdio.h>
#include <stdlib.h>

int T, N, c[102];

int main()
{
    int i, j,max;

    scanf("%d", &T);
    for(i = 1; i <= T; i++){

        scanf("%d", &N);
        for(j = 1; j <= N; j++)
            scanf("%d", &c[j]);

        max = c[1];
        for(j = 2; j <= N; j++)
            if(c[j] > max)
                max = c[j];
        printf("Case %d: %d\n", i, max);

    }

    return 0;
}
