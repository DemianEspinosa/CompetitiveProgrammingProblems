#include <stdio.h>
#include <stdlib.h>

int gcd(long long int a, long long int b){
    long long int aux;
    while(b){
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

long long int N, A, B;

int main()
{
    int i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        scanf("%lld%lld", &A, &B);
        if(gcd(A, B) == 1)
            printf("SI\n");
        else
            printf("NO\n");
    }

    return 0;
}
