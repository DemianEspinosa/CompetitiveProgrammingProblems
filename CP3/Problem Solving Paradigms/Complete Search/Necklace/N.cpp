#include <cstdio>

using namespace std;

int VT, v, D;

int main(){
	int i, c;
	scanf("%d %d", &VT, &v);
	while(VT){
		D = 0;
		c = 0;
		for(i = 1; i <= VT && VT > v * i; i++){
			if((VT * D - v * D * D) < (VT * i - v * i * i))
					D = i;
			else{
				if((VT * D - v * D * D) == (VT * i - v * i * i))
						c++;
		  	    }
		}
		if(c)
			printf("0\n");
		else
			printf("%d\n", D);

		scanf("%d %d", &VT, &v);
	}
}
		
