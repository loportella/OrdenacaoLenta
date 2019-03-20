#include <stdio.h>
#include "ordenar.h"
int main(int argc, char** argv) {
	int op,n;float t;
	unlink("a.txt");
	printf("Quantos valores: ");scanf("%d",&n);
		criaarq(n);
		if(n>0){
			
	do{
		printf("MENU PRINCIPAL:\n");menu(0);
		scanf("%d",&op);
		switch(op){
			case 1:menuBubble(n);break;
			case 2:menuSelection(n);break;
			case 3:menuInsertion(n);break;
		}
	}while(op!=0);
}
}
/*clock_t ini=clock();
t=((double)clock()-ini)/CLOCKS_PER_SEC;	
	printf("%f ms\n",t);
	*/
