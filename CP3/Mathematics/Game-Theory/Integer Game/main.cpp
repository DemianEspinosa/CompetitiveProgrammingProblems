#include <cstdio>

using namespace std;

int T;

char c[1005];

char resolve(int x, int y, int z){
    int res;
    res = (x + 2 * y) % 3;
    if(x + y + z == 1)
        return 'S';
    else{
        if(res == 1){
            if(x >= 1){
                if(z % 2 == 1){
                    return 'T';
                }
                else
                    return 'S';
            }
         else{
                return 'T';
            }
        }
        else{
            if(res == 2){
                if( y >= 1){
                    if(z % 2 == 1){
                        return 'T';
                    }
                    else
                        return 'S';

                    }
                else{
                    return 'T';
                }

            }
            else{
                if(z % 2 == 1){
                    return 'S';
                }
                else
                    return 'T';
            }
        }
    }
}

int main()
{
    int i,t,res1,res2,res3,dig;
    scanf("%d", &T);
    scanf("%c",&c[0]);
    for(t = 1; t <= T; t++){
        res1 = 0;
        res2 = 0;
        res3 = 0;
        scanf("%c", &c[0]);
        for(i = 1; c[i-1] != '\n'; i++)
            scanf("%c", &c[i]);
        dig = i - 1;
        for(i = 0; i < dig; i++)
            if(c[i] == '1' || c[i] == '4' || c[i] == '7')
                res1++;
            else
                if(c[i] == '2' || c[i] == '5' || c[i] == '8')
                    res2++;
                else
                    res3++;
        printf("Case %d: %c\n", t, resolve(res1, res2, res3));
    }

}
