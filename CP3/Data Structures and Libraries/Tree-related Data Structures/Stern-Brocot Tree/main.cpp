#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<long long int,long long int> pii;

int N;

char c[95];

int main()
{
    int i;
    scanf("%d", &N);
    pii l, m, r;


    while(N--){
        l.first = 0;
        l.second = 1;
        m.first = 1;
        m.second = 1;
        r.first = 1;
        r.second = 0;
        scanf("%s", &c);
        for(i = 0; c[i] != '\0'; i++){
            if(c[i] == 'L'){
                r.first = m.first;
                r.second = m.second;
                m.first += l.first;
                m.second += l.second;
            }else{
                l.first = m.first;
                l.second = m.second;
                m.first += r.first;
                m.second += r.second;

            }
        }
        printf("%lld/%lld\n", m.first, m.second);

    }

}
