#include <cstdio>

using namespace std;

int Z,L,M,I, visited[10002];

int main()
{
    int i,t,c;
    t = 1;
    scanf("%d%d%d%d", &Z, &I, &M, &L);
    while(Z){
        for(i = 1; i <= 10000; i++)
            visited[i] = 0;
        c = 1;
        while(visited[L] == 0){
            visited[L] = c;
            L = (Z * L + I) % M;
            if(L == 0)
                L = M;
            c++;
        }
        printf("Case %d: %d\n", t, c - visited[L]);
        t++;
        scanf("%d%d%d%d", &Z, &I, &M, &L);
    }
}
