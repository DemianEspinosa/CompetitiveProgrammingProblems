#include <cstdio>

using namespace std;

int N;
double p, dp[502][502], pr[502];

double prob(int i, int j){
    return dp[i][j-1] - dp[i][j];
}

int main()
{
    int i, j, k;
    double exp;
    scanf("%d%lf", &N, &p);
    while(N){
        for(i = 0; i <= N; i++)
            for(j = 0; j <= N; j++)
                dp[i][j] = 0;
        pr[0] = 1;
        for(i = 1; i <= N; i++)
            pr[i] = pr[i-1] * p;

        for(i = 1; i <= N; i++)
            for(j = i - 1; j >= 0; j--){
                dp[i][j] += dp[i][j+1];
                dp[i][j] += (1-p) * prob(i - 1, j + 1);
                if(j == i -1){
                    dp[i][j] += pr[j+1];

                }
                else{
                    dp[i][j] += pr[j+1] * (1-p) *(1 - dp[i - j - 2][j+1]);
                }
                for(k = 2; k <= j+1; k++){
                    dp[i][j] += pr[k - 1] * (1 - p) * prob(i-k,j+1);

                }

            }

       exp = 0;

       for(i = 1; i <= N; i++){
            exp += i * prob(N, i);

       }

       printf("%lf\n", exp);


    scanf("%d %lf", &N, &p);
    }


}
