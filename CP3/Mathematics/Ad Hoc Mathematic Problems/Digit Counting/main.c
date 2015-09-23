#include <stdio.h>
#include <stdlib.h>

int N, dig[12][10002], T;

void countdig(int x){
    int aux = x ;
    while(aux){
        dig[aux % 10][x]++;
        aux /= 10;
    }

}

int main()
{
    int i, j;

    for(i = 1; i <= 10000; i++){
        for(j = 0; j <= 9; j++){
            dig[j][i] = dig[j][i-1];
        }
        countdig(i);
    }

    scanf("%d", &T);
    for(i = 1; i <= T; i++){
        scanf("%d", &N);
        for(j = 0; j <= 8; j++)
            printf("%d ", dig[j][N]);
        printf("%d\n", dig[9][N]);

    }

    return 0;
}
