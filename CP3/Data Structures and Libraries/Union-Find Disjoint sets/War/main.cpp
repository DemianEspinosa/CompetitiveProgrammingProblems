#include <cstdio>
#include <algorithm>
#define MAXN 10003
using namespace std;

int N, enemies[MAXN], p[MAXN];

int areEnemies(int, int);
int areFriends(int, int);

int id(int i){
    if(p[i] == i)
        return i;
    else
        return p[i] = id(p[i]);
}

void join(int i, int j){
    p[id(i)] = id(j);
}

int setFriends(int i, int j){
    if(!areEnemies(i, j)){
        if(enemies[id(i)] != -1 && enemies[id(j)] != -1){
            join(enemies[id(i)], enemies[id(j)]);
            join(i, j);
            enemies[id(enemies[id(i)])] = id(i);
            enemies[id(i)] = id(enemies[id(i)]);
        } else if(enemies[id(i)] == -1 && enemies[id(j)] != -1){
                  enemies[id(i)] = enemies[id(j)];
                  join(i,j);
                  enemies[enemies[id(i)]] = id(i);

                } else if(enemies[id(i)] != -1 && enemies[id(j)] == -1){
                  enemies[id(j)] = enemies[id(i)];
                  join(i,j);
                  enemies[enemies[id(i)]] = id(i);

                } else{
                        join(i, j);
                    }


        return 1;
    }
    else
        return 0;
}

int setEnemies(int i, int j){
    if(!areFriends(i, j)){
        if(enemies[id(i)] != -1)
            setFriends(j, enemies[id(i)]);
        enemies[id(i)] = id(j);
        if(enemies[id(j)] != -1)
            setFriends(i, enemies[id(j)]);
        enemies[id(j)] = id(i);

        return 1;
      }
    else
        return 0;

}

int areFriends(int i, int j){
    return id(i) == id(j);
}

int areEnemies(int i, int j){
    return enemies[id(i)] == id(j);
}

int main()
{
    int i, j, c;

    scanf("%d%d", &N, &c);

    for(i = 0; i < N; i++)
        p[i] = i;

    for(i = 0; i < N; i++)
        enemies[i] = -1;


    while(c){
        scanf("%d%d", &i, &j);
        if(c == 1){
            if(!setFriends(i, j))
                printf("-1\n");
        }
        else if(c == 2){
                if(!setEnemies(i, j))
                   printf("-1\n");
             }
             else if(c == 3){
                    printf("%d\n", areFriends(i, j));
             }
             else{
                  printf("%d\n", areEnemies(i, j));
                    }

        scanf("%d", &c);
    }



}
