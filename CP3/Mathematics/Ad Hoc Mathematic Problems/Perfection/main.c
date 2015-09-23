#include <stdio.h>
#include <stdlib.h>

int N;

int main()
{
    int i, s;
    printf("PERFECTION OUTPUT\n");
    scanf("%d", &N);
    while(N){
        s = 0;

        if(N < 10)
            printf("    %d  ", N);
        else if(N < 100)
                printf("   %d  ", N);
             else if(N < 1000)
                     printf("  %d  ", N);
                  else if(N < 10000)
                          printf(" %d  ", N);
                        else
                            printf("%d  ", N);

        for(i = 1; 2*i <= N; i++)
            if(N % i == 0)
                s += i;
        if(s == N)
            printf("PERFECT\n");
        else if(s < N)
                printf("DEFICIENT\n");
             else
                printf("ABUNDANT\n");

        scanf("%d", &N);
    }
    printf("END OF OUTPUT\n");

        return 0;
}
