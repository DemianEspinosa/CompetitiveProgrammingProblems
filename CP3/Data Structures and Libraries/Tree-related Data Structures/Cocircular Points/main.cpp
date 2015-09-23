#include <cstdio>
#include <algorithm>
#define MOD 1000000009

using namespace std;

typedef pair<long long int,long long int> pii;

pii points[102];

int N;

int iscyclic(pii a, pii b, pii c, pii d){
    long long int ls, rs;
    ls = 4;
    ls = (ls * ((b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second))) % MOD ;
    ls = (ls * ((c.first - b.first)*(c.first - b.first) + (c.second - b.second)*(c.second - b.second))) % MOD ;
    ls = (ls * ((d.first - c.first)*(d.first - c.first) + (d.second - c.second)*(d.second - c.second))) % MOD ;
    ls = (ls * ((a.first - d.first)*(a.first - d.first) + (a.second - d.second)*(a.second - d.second))) % MOD ;

    rs =((d.first - b.first)*(d.first - b.first) + (d.second - b.second)*(d.second - b.second))*((c.first - a.first)*(c.first - a.first) + (c.second - a.second)*(c.second - a.second)) % MOD;
    rs = (rs - ((b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second))*((d.first - c.first)*(d.first - c.first) + (d.second - c.second)*(d.second - c.second))) % MOD;
    rs = (rs - ((c.first - b.first)*(c.first - b.first) + (c.second - b.second)*(c.second - b.second))*((d.first - a.first)*(d.first - a.first) + (d.second - a.second)*(d.second - a.second))) % MOD;
    rs = (rs * rs) % MOD;
    if(ls == rs)
        return 1;
    else
        return 0;
}

int main()
{
    int i, j, k, p, max, c;


    scanf("%d", &N);
    while(N){
        if(N == 1)
            max = 1;
        else
            max = 2;

        for(i = 1; i <= N; i++)
            scanf("%lld%lld", &points[i].first, &points[i].second);

        for(i = 1; i + 2 <= N; i++)
            for(j = i+1; j + 1 <= N; j++)
                for(k = j+1; k <= N; k++){
                    if((points[j].second - points[i].second)*(points[k].first - points[j].first) != (points[k].second - points[j].second)*(points[j].first - points[i].first)){
                        c = 3;
                        for(p = 1; p <= N; p++){
                            if(p != i && p != j && p != k)
                                if(iscyclic(points[i], points[p], points[j], points[k]) || iscyclic(points[i], points[j], points[p], points[k]) || iscyclic(points[i], points[j], points[k], points[p]))
                                    c++;
                        }
                        if(max < c)
                            max = c;

                    }
                    else{
                        if(max < 2)
                            max = 2;
                    }
                }
        printf("%d\n", max);
        scanf("%d", &N);
    }



}
