#include <stdio.h>
#include <stdlib.h>

int K, N, M, X, Y;

int main()
{
    int i;

    scanf("%d", &K);

    while(K){
        scanf("%d%d", &N, &M);

        for(i = 1; i <= K; i++){
            scanf("%d%d", &X, &Y);
            if(X == N || Y == M )
                printf("%s\n","divisa");
            else if(X > N && Y > M)
                    printf("%s\n","NE");
                 else if(X > N && Y < M)
                        printf("%s\n","SE");
                      else if (X < N && Y > M)
                            printf("%s\n","NO");
                            else
                                printf("%s\n","SO");
        }
        scanf("%d", &K);
    }


    return 0;
}
