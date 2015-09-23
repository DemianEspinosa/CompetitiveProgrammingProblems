#include <cstdio>

using namespace std;

int P, H, O;

int main(){
	scanf("%d %d %d", &P, &H, &O);
	printf("%s\n", O - P >= H ? "Props win!" : "Hunters win!");
}
