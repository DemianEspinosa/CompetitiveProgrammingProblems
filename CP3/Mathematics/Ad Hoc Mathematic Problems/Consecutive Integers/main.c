#include <stdio.h>
#include <stdlib.h>

int n, N, k;

int main()
{
    int i, k;
    scanf("%d", &N);
    while(N != -1){
        k = 1;
        for(i = 1; i <= 45000; i++)
            if((2 * N - (i*(i-1))) % (2*i) == 0 && (2 * N  > i*(i-1)))
                k = i;

        printf("%d = %d + ... + %d\n", N, ((2 * N - (k*(k-1))) / (2*k)), (((2 * N - (k*(k-1))) / (2*k)) + k - 1) );
        scanf("%d", &N);
    }




    return 0;
}
