#include <stdio.h>
#include <stdlib.h>

int T, N;


int main()
{
    int i;
    double d = 1.4142135623;
    scanf("%d", &T);
    for(i = 1; i <= T; i++){
        scanf("%d", &N);
        if(N == 1)
            printf("0.000\n");
        else
            printf("%.3lf\n", (((N-2)*(N-2))*d + 4*N - 4 ));

        printf("\n");
    }


    return 0;
}
