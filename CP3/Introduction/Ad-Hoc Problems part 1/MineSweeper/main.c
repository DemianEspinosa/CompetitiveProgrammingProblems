#include <stdio.h>
#include <stdlib.h>

int N, M, X;
char mines[105][105];

int main()
{
    int i, j, c;
    scanf("%d%d", &N, &M);
    X = 1;

    while(N){
        for(i = 0; i <= M+1; i++)
            mines[0][i] = '.';
        for(i = 0; i <= M + 1; i++)
            mines[N+1][i] = '.';
        for(i = 0; i <= N + 1; i++)
            mines[i][0] = '.';
        for(i = 0; i <= N + 1; i++)
            mines[i][M+1] = '.';

        for(i = 1; i <= N; i++)
            for(j = 1; j <= M; j++)
                do{
                    scanf("%c", &mines[i][j]);
                }while(mines[i][j] != '.' && mines[i][j] != '*');

        printf("Field #%d:\n", X);

        for(i = 1; i <= N; i++)
            for(j = 1; j <= M; j++){
                c = 0;
                if(mines[i+1][j-1] == '*')
                    c++;
                if(mines[i+1][j] == '*')
                    c++;
                if(mines[i+1][j+1] == '*')
                    c++;
                if(mines[i][j-1] == '*')
                    c++;
                if(mines[i][j+1] == '*')
                    c++;
                if(mines[i-1][j-1] == '*')
                    c++;
                if(mines[i-1][j] == '*')
                    c++;
                if(mines[i-1][j+1] == '*')
                    c++;

                if(j == M){
                    if(mines[i][j] == '*')
                        printf("*\n");
                    else
                        printf("%d\n", c);
                }
                else{
                    if(mines[i][j] == '*')
                        printf("*");
                    else
                        printf("%d", c);

                }



            }


        X++;
        scanf("%d%d", &N, &M);
        if(N)
            printf("\n");
    }

    return 0;
}
