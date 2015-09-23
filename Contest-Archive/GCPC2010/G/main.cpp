#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define INF -100000

int T, i, j, ar[15][15], dp[15][3200], k, ans;

int main()
{
    cin >> T;
    while (T--){

        for (i = 0; i < 11; i++)
            for (j = 0; j < 11; j++)
                cin >> ar[i][j];

        for (i = 0; i < 3200; i++)
            for(j = 0; j < 11; j++)
                dp[j][i] = INF;

        for (i = 3200; i >= 0; i--)
            for(j = 10; j >= 0; j--){
                for (k = 0; k < 11; k++){
                    if(ar[j][k] > 0 && ((i&(1<<k)) == 0)){
                        dp[j][i] = max(dp[j][i], ar[j][k] + dp[j+1][i+(1<<k)]);

                    }
                }
            }

        cout << dp[0][0] << endl;




    }
}
