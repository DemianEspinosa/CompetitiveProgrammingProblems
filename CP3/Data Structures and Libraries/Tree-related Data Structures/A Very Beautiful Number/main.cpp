#include <cstdio>
#define MAX 1000005

using namespace std;

int p, x, num[MAX], LD[MAX], LDR[MAX], ar;

int main()
{
    int i, a, pow, ans;
    ans = MAX;
    scanf("%d%d", &p, &x);
    if(p >= 6){
        LDR[p-1] = 10;
    for(a = 1; a <= 9; a++){
        LD[p] = a - 1;
        for( i = 3; i <= p - 1; i++)
            LD[i] = 9;
        LD[2] = (((100 - x) * a)/10) % 10;
        LD[1] = ((100 - x) * a) % 10;

        for(i = 1; i <= p-5; i++){
            num[i] = (LD[i] * 9 ) % 10;
            if(LD[i + 1] >= (((10 * x - 1) * num[i])/10) % 10)
                LD[i + 1] -= (((10 * x - 1) * num[i])/10) % 10;
            else{
                if(LD[i + 2]){
                    LD[i + 1] = LD[i + 1] + 10 - ((((10 * x - 1) * num[i])/10) % 10);
                    LD[i + 2]--;
                }
                else{
                    LD[i + 1] = LD[i + 1] + 10 - ((((10 * x - 1) * num[i])/10) % 10);
                    LD[i + 2] = 9;
                    LD[i + 3]--;
                }



            }

            if(LD[i + 2] >= (((10 * x - 1) * num[i])/100) % 10)
                LD[i + 2] -= (((10 * x - 1) * num[i])/100) % 10;
            else{
                if(LD[i + 3]){
                    LD[i + 2] = LD[i + 2] + 10 - ((((10 * x - 1) * num[i])/100) % 10);
                    LD[i + 3]--;
                }
                else{
                    LD[i + 2] = LD[i + 2] + 10 - ((((10 * x - 1) * num[i])/100) % 10);
                    LD[i+3] = 9;
                    LD[i + 4]--;
                }
            }
        }
        if((LD[p-4] + 10 * LD[p-3] + 100* LD[p-2] + 1000*LD[p-1] + 10000*LD[p]) % (10*x - 1) == 0){
            num[p-4] = ((LD[p-4] + 10 * LD[p-3] + 100* LD[p-2] + 1000*LD[p-1] + 10000*LD[p])/(10*x - 1)) % 10;
            num[p-3] = (((LD[p-4] + 10 * LD[p-3] + 100* LD[p-2] + 1000*LD[p-1] + 10000*LD[p])/(10*x - 1))/10) % 10;
            num[p-2] = (((LD[p-4] + 10 * LD[p-3] + 100* LD[p-2] + 1000*LD[p-1]+ 10000*LD[p])/(10*x - 1))/100) % 10;
            num[p-1] = (((LD[p-4] + 10 * LD[p-3] + 100* LD[p-2] + 1000*LD[p-1] + 10000*LD[p])/(10*x - 1))/1000) % 10;



            for(i = p-1; num[i] == LDR[i]; i--);

            if(num[i] < LDR[i]){
                ar = a;
                for(i = 1 ; i <= p - 1; i++)
                    LDR[i] = num[i];
            }
        }
    }

    if(LDR[p-1] != 10){
        for(i = p - 1; i >= 1; i--)
            printf("%d", LDR[i]);
        printf("%d", ar);

        }
    else
        printf("Impossible");

    }
    else{
        if(p >= 2){
            for(a = 1; a <= 9; a++){
            pow = 10;
            for(i = 1; i <= p-2; i++)
                pow = pow * 10;
            if(a*(pow - x) % (10*x - 1) == 0){
                if ((a*(pow - x))/ (10*x - 1) < ans){
                    ar = a;
                    ans = (a*(pow - x))/ (10*x - 1);
                }
            }
        }
        if(ans < MAX){
            printf("%d", ans);
            printf("%d", ar);
        }
        else
            printf("Impossible");
        }
        else{
            if(x == 1)
                printf("1");
            else
                printf("Impossible");


        }






    }


}




