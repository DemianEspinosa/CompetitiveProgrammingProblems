#include <cstdio>

using namespace std;

long long int N, pi[1000005];

int main()
{
    long long  int i,res;
    scanf("%lld", &N);
    while(N){
        res = 0;
        for(i = 1; i <= N; i++){
            scanf("%lld", &pi[i]);
            res = (res ^ pi[i]);
        }
        printf("%s\n", res == 0 ? "NO" : "YES");
        scanf("%lld", &N);
    }

}
