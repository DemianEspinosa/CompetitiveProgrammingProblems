#include <cstdio>

using namespace std;

int N, ans[3];

int searchGauss(int x){
    int lo,hi,mid;
    lo = 1;
    hi = 10000;
    mid = (lo + hi )/2;
    while(lo != hi){
        if((mid * (mid + 1))/2 <= x)
            lo = mid + 1;
        else
            hi = mid;
        mid = (lo + hi)/2;
    }
    return mid - 1;
}

int main()
{
    int i,g,res;
    while(scanf("%d", &N) != EOF){
        g = searchGauss(N);
        res = N - (g * (g + 1))/2;
        ans[g % 2] = g;
        ans[(g + 1) % 2] = 1;
        if(res){
            ans[g % 2]++;
            for(i = 1; i < res; i++){
                ans[g % 2]--;
                ans[(g + 1) % 2]++;
            }
        }
        printf("TERM %d IS %d/%d\n", N, ans[0] , ans[1]);
    }
}
