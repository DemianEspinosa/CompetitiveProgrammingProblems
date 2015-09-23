#include <cstdio>
#include <algorithm>



using namespace std;

int N, a[105];

int dig(int x){
    if(x >= 10)
        return dig(x/10) + 1;
    else
        return 1;
}

int main()
{
    int i,s,t,dnum, dden,dint;
    t = 1;
    scanf("%d", &N);
    while(N){
        printf("Case %d:\n", t);
        s = 0;
        for(i = 1; i <= N; i++){
            scanf("%d", &a[i]);
            s += a[i];
        }
        if(s >= 0){
            if(s % N == 0){
                printf("%d\n", s/N);
            }
            else{
                if(s < N){
                    dnum = dig(s/__gcd(s,N));
                    dden = dig(N/__gcd(s,N));
                    for(i = 1; i <= dden - dnum; i++)
                        printf(" ");
                    printf("%d\n",s/__gcd(s,N));
                    for(i = 1; i <= dden; i++)
                        printf("-");
                    printf("\n");
                    printf("%d\n", N/__gcd(s,N));

                }
                else{
                    dnum = dig((s % N)/__gcd((s % N),N));
                    dden = dig(N/__gcd((s % N),N));
                    dint = dig(s/N);
                    for(i = 1; i <= dden - dnum + dint; i++)
                        printf(" ");
                    printf("%d\n",(s % N)/__gcd((s % N),N));
                    printf("%d", s/N);
                    for(i = 1; i <= dden; i++)
                        printf("-");
                    printf("\n");
                    for(i = 1; i <= dint; i++)
                        printf(" ");
                    printf("%d\n", N/__gcd((s % N),N));
                }

            }


        }
        else{
            s = -s;
            if(s % N == 0){
                printf("- %d\n", s/N);
            }
            else{
                if(s < N){
                    dnum = dig(s/__gcd(s,N));
                    dden = dig(N/__gcd(s,N));
                    for(i = -1; i <= dden - dnum; i++)
                        printf(" ");
                    printf("%d\n",s/__gcd(s,N));
                    printf("- ");
                    for(i = 1; i <= dden; i++)
                        printf("-");
                    printf("\n");
                    printf("  ");
                    printf("%d\n", N/__gcd(s,N));

                }
                else{
                    dnum = dig((s % N)/__gcd((s % N),N));
                    dden = dig(N/__gcd((s % N),N));
                    dint = dig(s/N);
                    for(i = -1; i <= dden - dnum + dint; i++)
                        printf(" ");
                    printf("%d\n",(s % N)/__gcd((s % N),N));
                    printf("- %d", s/N);
                    for(i = 1; i <= dden; i++)
                        printf("-");
                    printf("\n");
                    for(i = -1; i <= dint; i++)
                        printf(" ");
                    printf("%d\n", N/__gcd((s % N),N));
                }

            }



        }
        t++;
        scanf("%d", &N);
    }

}
