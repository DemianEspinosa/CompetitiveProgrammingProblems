#include <cstdio>
#include <algorithm>
#define MAX 20005

using namespace std;

int N, M, D[MAX], H[MAX], gold;

int main()
{
    int i, j;
    scanf("%d%d", &N, &M);
    while(N){
        for(i = 0; i < N; i++)
            scanf("%d", &D[i]);
        for(i = 0; i < M; i++)
            scanf("%d", &H[i]);
        sort(D, D + N);
        sort(H, H + M);

        gold = i = j = 0;
        while(i < N && j < M){
            while(D[i] > H[j] && j < M)
                j++;
            if(j == M)
                break;
            gold += H[j];
            i++;
            j++;

        }

        if(i == N)
            printf("%d\n", gold);
        else
            printf("Loowater is doomed!\n");

        scanf("%d%d", &N, &M);
    }
}
