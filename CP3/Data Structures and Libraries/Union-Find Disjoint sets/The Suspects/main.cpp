#include <cstdio>
#include <algorithm>

int N, M, p[30003], num[30003];

int id(int x){
    if(p[x] == x)
        return x;
    else
        return p[x] = id(p[x]);
}

void join(int i, int j){
    if(id(i) != id(j)){
        num[id(j)] += num[id(i)];
        p[id(i)] = id(j);
    }

}


using namespace std;

int main()
{
    int i, j, k, a, b;
    scanf("%d%d", &N, &M);
    while(N){
        for(i = 0; i <= N-1; i++){
            p[i] = i;
            num[i] = 1;
        }

        for(i = 1; i <= M; i++){
            scanf("%d%d", &k, &a);
            for(j = 2; j <= k; j++){
                scanf("%d", &b);
                join(a, b);
            }

        }

        printf("%d\n", num[id(0)]);


    scanf("%d%d", &N, &M);
    }

}
