#include <cstdio>

using namespace std;

int T, N, r[100005];

int main()
{
    int i,j,t,lo,mid,hi,str;
    scanf("%d", &T);
    for(t = 1; t <= T; t++){
        scanf("%d", &N);
        for(i = 1; i <= N; i++)
            scanf("%d", &r[i]);
        lo = 1;
        hi = 10000007;
        while(lo != hi){
            mid = (lo + hi)/2;
            str = mid;
            for(j = 1; r[j] - r[j-1] <= str && j <= N; j++)
                if(r[j] - r[j-1] == str)
                    str--;
            if(j > N)
                hi = mid;
            else
                lo = mid + 1;
        }
        mid = (lo + hi)/2;
        printf("Case %d: %d\n", t, mid);
    }

}
