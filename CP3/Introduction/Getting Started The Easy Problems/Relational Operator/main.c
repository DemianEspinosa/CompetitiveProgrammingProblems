#include <stdio.h>
#include <stdlib.h>

int T, A, B;

int main()
{
    int i;
    scanf("%d", &T);
    for(i = 1; i <= T; i++){
        scanf("%d%d", &A, &B);
        if(A < B)
            printf("%c\n",'<');
        else
            if(A == B)
                printf("%c\n",'=');
            else
                printf("%c\n",'>');
    }

    return 0;
}
