#include <stdio.h>
#include <stdlib.h>

int T, A, B, C;

int main()
{
    int i;
    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        scanf("%d%d%d", &A, &B, &C);
        if((A > B && A < C) || (A < B && A > C))
            printf("Case %d: %d\n", i, A);
        else if ((B > A && B < C) || (B < A && B > C))
            printf("Case %d: %d\n", i, B);
             else
                printf("Case %d: %d\n", i, C);

    }

    return 0;
}
