#include <cstdio>

using namespace std;

int N, M, c[1005];

int main()
{
    int i,j,lo,mid,hi,tar;
    while(scanf("%d%d", &N, &M) != EOF){
        for(i = 1; i <= N; i++)
            scanf("%d", &c[i]);
        lo = 1;
        hi = 1000000005;
        while(lo != hi){
            mid = (lo + hi)/2;
            j = 1;
            for(i = 1; i <= M; i++){
                for(tar = mid; tar >= c[j] && j <= N; j++)
                    tar -= c[j];
                }
            if(j > N)
                hi = mid;
            else
                lo = mid + 1;
            }
            mid = (lo + hi)/2;
            printf("%d\n", mid);
        }
}
