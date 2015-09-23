#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

char c[1000005];

int flag;

void addone(int current){
	if(current == 0 && c[current] == '1'){
		printf("11");
		c[current] = '0';
		flag = 0;
	}else if(c[current] == '0')
		c[current] = '1';
	else if(c[current - 1] == '1'){
		c[current] = '0';
		c[current - 1] = '0';
		}
	else{
		c[current] = '0';
		c[current - 1] = '1';
		addone(current - 2);
		}
}


int main(){
	int i;
	while(scanf("%s", c) != EOF){
		flag = 1;
		if(c[0] == '1' && c[1] == '1' && strlen(c) == 2)
			printf("0\n");
		else{
			addone(strlen(c) - 1);
			for(i = 0; c[i] == '0' && flag;  i++);
			printf("%s\n", &(c[i]));
		}
	}
}
