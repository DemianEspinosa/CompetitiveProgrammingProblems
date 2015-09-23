#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000002],N;

int main()
{
    int sp,sn,i,MAX;

    sp = 0;
    MAX = -100000005;
    scanf("%d", &N);
    while(N){
        for(i = 0; i < N; i++)
            scanf("%d",&a[i]);
        i = 0;
        while(i < N){
            for(; a[i] >= 0 && i<N; i++)
                sp += a[i];
            MAX = max(sp,MAX);
            sn = 0;
            for(; a[i] <= 0 && i<N; i++)
                sn += a[i];
            if(sp+sn>0)
                sp += sn;
            else
                sp = 0;
        }
        printf("%d\n",MAX);
        scanf("%d", &N);
    }
}
