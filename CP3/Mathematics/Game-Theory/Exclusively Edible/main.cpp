#include <cstdio>

using namespace std;

int T,N,M,R,C;

int main()
{
    int n1,n2,n3,n4;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &M, &N, &R, &C);
        n1 = C;
        n2 = N - C - 1;
        n3 = R;
        n4 = M - R - 1;

        printf("%s\n", (n1 ^ n2 ^ n3 ^ n4) == 0 ? "Hansel" : "Gretel");
    }
}
