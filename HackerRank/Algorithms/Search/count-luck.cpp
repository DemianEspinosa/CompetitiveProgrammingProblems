#include <cstdio>

using namespace std;

int T, N, M, K, endx, endy, startx, starty;

char board[105][105];

int main(){
	int i, j; 
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		for(i = 1; i <= N; i++){
			for(j = 1; j <= M; j++)
				do{
					scanf("%c", &board[i][j]);
				}while(board[i][j] != '.' && board[i][j] != 'X' && board[i][j] != 'M' && board[i][j] != '*');
		}
		
	}
}

