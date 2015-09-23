#include <cstdio>
#include <algorithm>
#include <cmath>


using namespace std;

long long T, N, x[505];

long long P(int i){
    return ((x[1]*(i-2)*(i-3)*(i-4))/(-6)) + ((x[2]*(i-1)*(i-3)*(i-4))/2) + ((x[3]*(i-1)*(i-2)*(i-4))/(-2)) + ((x[4]*(i-1)*(i-2)*(i-3))/6);
}

int main()
{
    int i;
    scanf("%d", &T);
    while(T--){
        scanf("%lld", &N);
        for(i = 1; i <= N; i++)
            scanf("%lld", &x[i]);
        if(N <= 4)
            printf("YES\n");
        else{
            for(i = 5; i <= N; i++)
                if(P(i) != x[i])
                    break;
            if(i <= N)
                printf("NO\n");
            else
                printf("YES\n");
        }

    }

}
