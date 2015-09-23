#include <stdio.h>
#include <stdlib.h>

int R, N, X;

int main()
{
    X = 1;
    scanf("%d%d", &R, &N);
    while(R){
        if(R % N == 0)
            if((R/N) - 1 < 27)
                printf("Case %d: %d\n", X, (R/N - 1));
            else
                printf("Case %d: impossible\n", X);
        else
            if((R/N) < 27)
               printf("Case %d: %d\n", X, (R/N));
            else
               printf("Case %d: impossible\n", X);
        X++;
        scanf("%d%d", &R, &N);
    }

    return 0;
}
