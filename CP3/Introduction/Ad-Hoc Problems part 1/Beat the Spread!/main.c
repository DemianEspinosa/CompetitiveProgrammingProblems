#include <stdio.h>
#include <stdlib.h>

int S, D, N;

int main()
{
    int i, a, b;

    scanf("%d", &N);

    for(i = 1; i <= N; i++){
        scanf("%d%d", &S, &D);
        if(S % 2 == D % 2 && S >= D)
            printf("%d %d\n", (S+D)/2, (S-D)/2);
        else
            printf("impossible\n");

    }
    return 0;
}
