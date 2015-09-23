#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T, C;

int absurdity(int x){
    int dig, d;
    while(x % 10 == 0)
            x /= 10;
    d = x % 10;
    for(dig = 0; x; x /=10, dig++);
    if(d == 5)
        return 2*dig - 1;
    else
        return 2*dig;
}

int main()
{
    int i, target;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &C);
        while(C % 10 == 0)
            C /= 10;
        target = absurdity(C);
        if(C > 100)
            printf("absurd\n");
        else{
            for(i = C - C/20; absurdity(i) >= target && i <= C + C/20; i++);
            if(i > C + C/20)
                printf("not absurd\n");
            else
                printf("absurd\n");
            }
    }

}
