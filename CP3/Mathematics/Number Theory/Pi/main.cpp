#include <cstdio>
#include <cmath>


using namespace std;

int gcd(int x, int b){
    int aux;
    while(b){
        aux = b;
        b = x % b;
        x = aux;
    }
    return x;
}

int N,a[52];

int main()
{

    int c,i,j;
    scanf("%d", &N);
    while(N){
        c = 0;
        for(i = 1; i <= N; i++)
            scanf("%d", &a[i]);

        for(i = 1; i < N; i++)
            for(j = i+1; j <= N; j++)
                if(gcd(a[i],a[j]) == 1)
                    c++;
        if(c)
            printf("%.6lf\n", sqrt((((double)N*(N-1) * 3) / c)));
        else
            printf("No estimate for this data set.\n");
        scanf("%d", &N);
    }


}
