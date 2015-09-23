#include <stdio.h>
#include <stdlib.h>

int T, R, C, N;


int main()
{
    int i, j, k;
    char land[105][105], aux[105][105];

    scanf("%d", &T);
    for(i = 1; i <= T; i++){
        scanf("%d%d%d", &R, &C, &N);

        for(j = 1; j <= R; j++)
            for(k = 1; k <= C; k++)
                do{
                    scanf("%c", &land[j][k]);

                }while(land[j][k] != 'R' && land[j][k] != 'P' && land[j][k] != 'S');

        for(j = 0; j <= C+1; j++)
            land[0][j] = 'N';
        for(j = 0; j <= C+1; j++)
            land[R+1][j] = 'N';
        for(j = 0; j <= R+1; j++)
            land[j][0] = 'N';
        for(j = 0; j <= R+1; j++)
            land[j][C+1] = 'N';

        for(j = 1; j <= R; j++)
            for(k = 1; k <= C; k++)
                aux[j][k] = land[j][k];

        for(; N; N--){

            for(j = 1; j <= R; j++)
                for(k = 1; k <= C; k++){
                    if(aux[j][k] == 'R'){
                        if(land[j][k-1] == 'P' || land[j][k+1] == 'P' || land[j-1][k] == 'P' || land[j+1][k] == 'P' )
                            aux[j][k] = 'P';

                    } else if(aux[j][k] == 'P'){
                        if(land[j][k-1] == 'S' || land[j][k+1] == 'S' || land[j-1][k] == 'S' || land[j+1][k] == 'S' )
                            aux[j][k] = 'S';


                    } else{
                       if(land[j][k-1] == 'R' || land[j][k+1] == 'R' || land[j-1][k] == 'R' || land[j+1][k] == 'R' )
                            aux[j][k] = 'R';


                    }

                }

            for(j = 1; j <= R; j++)
                for(k = 1; k <= C; k++)
                    land[j][k] = aux[j][k];

        }

        for(j = 1; j <= R; j++)
                for(k = 1; k <= C; k++)
                    if(k != C)
                        printf("%c", land[j][k]);
                    else
                        printf("%c\n", land[j][k]);

        if(i < T)
            printf("\n");
    }


    return 0;
}
