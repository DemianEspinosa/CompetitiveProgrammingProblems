#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool cocopos(int z, int x){
    int c, n;
    n = z;
    for(c = 0; c <= x && n % x == 1; c++)
        n = ((n-1)/x)*(x-1);
    if(c == x && n % x == 0)
        return true;
    else
        return false;


}

int N;

int main()
{
    int j, max;
    scanf("%d", &N);
    while(N != -1){
        max = 1;
        for(j = 2; j <= 5; j++){
            if(cocopos(N, j))
                max = j;
        }

        if(max == 1)
            printf("%d coconuts, no solution\n", N);
        else
            printf("%d coconuts, %d people and 1 monkey\n", N, max);

    scanf("%d", &N);
    }

    return 0;
}

