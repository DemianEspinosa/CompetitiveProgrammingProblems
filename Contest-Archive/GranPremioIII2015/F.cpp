#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

int T, i, j, N, S, D, mov, players[10], board[105];
bool w = false, winner[10];

int main()
{
    scanf("%d", &T);

    while(T--){

        w = false;

        scanf("%d %d %d", &N, &S, &D);
        for(i = 0; i < S; i++)
            scanf("%d", &board[i]);

        fill(players, players+10, 0);
        fill(winner, winner+10, false);
        for(i = 0; i < D; i++){

            scanf("%d", &mov);
	    int counr = 0;
            while(winner[i%N] && counr < 11){
                D++; i++;
		counr++;
            }
            players[i%N] = players[i%N] + mov + board[players[i%N]+mov];
           
            if(players[i%N] == S-1){

                if(w)
                    printf(" ");

                w = true;
                winner[i%N] = true;
                printf("%d",i%N + 1);


            }

        }

        if (!w){
            printf("-1");
//	} else {
//		for(i = N-1; i >=0; i--)
//			if(!winner[i])
//				printf(" %d", i+1);
		
	}
        printf("\n");


    }
}
