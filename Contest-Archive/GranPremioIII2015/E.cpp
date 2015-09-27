#include <cstdio>

using namespace std;

long long N, M;

long long leastsquare(long long x){
    long long lo, mid, hi;
    lo = 1;
    hi = 100000000;
    mid = (lo + hi)/2;
    while(lo != hi){
        mid = (lo + hi)/2;
        if(mid * mid >= x)
            hi = mid;
        else
            lo = mid + 1;
    }
    mid = (lo + hi)/2;
    return mid;
}

long long highsquare(long long x){
    long long lo, mid, hi;
    lo = 1;
    hi = 100000000;
    mid = (lo + hi)/2;
    while(lo != hi){
        mid = (lo + hi)/2;
        if(mid * mid > x)
            hi = mid;
        else
            lo = mid + 1;
    }
    mid = (lo + hi)/2;
    return mid - 1;
}

int main()
{
    long long i, j;
    while (scanf("%lld %lld", &N, &M), N){
        i = leastsquare(N);
        j = highsquare(M);
        printf("%lld\n", M - N + i - j);
    }

}
