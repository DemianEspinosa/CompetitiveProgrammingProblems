#include <cstdio>

using namespace std;

int N, a[12];
bool flag;

int main(){
	int i;
	scanf("%d", &N);
	printf("Lumberjacks:\n");
	while(N--){
		for(i = 1; i <= 10; i++)
			scanf("%d", &a[i]);
		flag = false;
		for(i = 2; i <= 10; i++)
			if(a[i] > a[i - 1])
				break;
		if(i > 10)
			flag = true;
		for(i = 2; i <= 10; i++)
			if(a[i] < a[i - 1])
				break;
		if(i > 10)
			flag = true;
		
		printf("%s\n", flag ? "Ordered" : "Unordered");
	}
}


