#include <cstdio>

using namespace std;

long long int A, B, C, D, E;

int main()
{
    scanf("%lld %lld %lld %lld %lld", &A, &B, &C, &D, &E);
    while(A){
        printf("%d\n", A*B*C*D*D*E*E);
        scanf("%lld %lld %lld %lld %lld", &A, &B, &C, &D, &E);
    }
}
