#include <iostream>
#include <cstdio>
 
using namespace std;
    
int a1, b1, a2, b2, c1, d1, c2, d2;
     
int main() {
    	int i;
	double esp1, esp2;
	scanf("%d %d %d %d %d %d %d %d", &a1, &b1, &a2, &b2, &c1, &d1, &c2, &d2);
	esp1 = 1.0 *((b1*(b1 + 1) - (a1 - 1) * a1))/(2 * (b1 - a1 + 1));
	esp1 += 1.0 *((b2*(b2 + 1) - (a2 - 1) * a2))/(2 * (b2 - a2 + 1));
 	esp2 = 1.0 *((d1*(d1 + 1) - (c1 - 1) * c1))/(2 * (d1 - c1 + 1));
	esp2 += 1.0 *((d2*(d2 + 1) - (c2 - 1) * c2))/(2 * (d2 - c2 + 1));
 	if(esp1 > esp2)
		printf("Gunnar\n");
	else if(esp1 == esp2)
		printf("Tie\n");
	else
		printf("Emma\n");
	return 0;
     }
