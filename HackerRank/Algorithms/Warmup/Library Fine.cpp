#include<cstdio>

using namespace std;

int DE, DR, ME, MR, YE, YR;

int main(){
	scanf("%d %d %d %d %d %d", &DR, &MR, &YR, &DE, &ME, &YE);
	if(YR > YE)
		printf("10000");
	else if(MR > ME && YR == YE)
		printf("%d", (MR - ME)*500);
	else if(DR > DE && MR == ME && YR == YE)
		printf("%d", (DR - DE)*15);
	else
		printf("0");
	}


