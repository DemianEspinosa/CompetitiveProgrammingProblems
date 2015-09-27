#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long choose[20][20], E, O, i, j;

int main()
{

    for(i = 0; i < 20; i++){
        choose[i][0] = choose[i][i] = 1;
        for(j = 1; j < i; j++)
            choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
    }


    while (scanf("%d %d", &E, &O), E+O){

        long long ans = 1;
        long long ans2 = 1;
        if(E == 0){
            for(i = 0; i < O; i++)
                ans *= 5;
            ans *= 2;
        } else if(O == 0){
            for(i = 1; i < E; i++)
                ans*=5;
            if(E>1){
                ans *= 8;
            }

            else
                ans = 9;
        } else {

            ans = 4*choose[E+O-1][O];

            for(i = 0; i < E+O-1; i++){
                ans2*=5;
            }

            ans += 5*choose[E+O-1][E];

            ans *= ans2;
            ans *= 2;
        }

        printf("%lld\n", ans);

    }

}
