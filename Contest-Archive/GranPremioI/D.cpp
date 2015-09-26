#include <cstdio>
#include <cmath>

#define MAXN 150

using namespace std;

int W, H, S, sl[MAXN];

struct AugmentedMatrix{
	double mat[MAXN][MAXN + 1];
};

struct ColumnVector{
	double vec[MAXN];
};

ColumnVector GaussJordan(int N, AugmentedMatrix Aug){
	int i, j, k, l;
	double t;
	ColumnVector X;

	for (j = 0; j < N - 1; j++){ //the forward elimination phase
		l = j ;
		for (i = j + 1; i < N; i++) //which row has the largest column value
			if(fabs(Aug.mat[i][j]) > fabs(Aug.mat[l][j]))
				l = j;
		//swap this pivot row, reason: to minimize floating point error
		for(k = j; k <= N; k++)
			t = Aug.mat[j][k], Aug.mat[j][k] = Aug.mat[l][k], Aug.mat[l][k] = t;
		
		for(i = j + 1; i < N; i++) //the actual forward elimination phase
			for(k = N; k >= j; k--)
				Aug.mat[i][k] -= Aug.mat[j][k] * Aug.mat[i][j] / Aug.mat[j][j];
	}

	for( j = N - 1; j >= 0; j--){ //The back substitution phase
		for(t = 0.0, k = j + 1; k < N; k++)
			t += Aug.mat[j][k] * X.vec[k];
		X.vec[j] = (Aug.mat[j][N] - t)/Aug.mat[j][j]; // The answer is here
	}
	return X;
}

int f(int x){
	if(x <= W * H - 1)
		return x;
	else
		return 2 * (W * H - 1) - x;
}



int main(){
	int i, j, a, b;
	AugmentedMatrix A;
	ColumnVector E;
	while (scanf("%d %d %d", &W, &H, &S) != EOF){
		for (i = 0; i < W * H; i++)
			sl[i] = i;
		for(i = 0; i < W * H; i++)
			for(j = 0; j <= W * H; j++)
				A.mat[i][j] = 0;
		for (i = 0; i < S; i++){
			scanf("%d %d", &a, &b);
			sl[a - 1] = b - 1;
		}

		A.mat[W * H - 1][W * H - 1] = 1;
		for(i = 0; i < W * H - 1; i++){
			A.mat[i][i] = 1;
			for(j = 1; j <= 6; j++)
				A.mat[i][sl[f(i + j)]] -= 1.0/6;
			A.mat[i][W * H] = 1;
		}
		//for (i = 0; i < W * H; i++)
		//	for (j = 0; j <= W * H; j++)
		//		printf("i: %d, j: %d, A: %.2lf\n", i, j, A.mat[i][j]);

		E = GaussJordan(W*H, A);
		printf("%.8lf\n", E.vec[0]);
	}
}
