#include <cstdio>

using namespace std;

long long int A, B;

int main()
{
    while(scanf("%lld %lld", &A, &B) != EOF){
        printf("%lld\n", (A ^ B));
    }
}
