#include <stdio.h>
#include "ordenar.h"
int main(int argc, char** argv) {
	int op,n;float tb;
	printf("Quantos valores: ");scanf("%d",&n);
		Entrada(n);
		if(n>0){
		tb=Bubblesort(n);	
	do{
		printf("op ");scanf("%d",&op);
		switch(op){
			case 1:BubblesortMenu(n);break;
		}
	}while(op!=0);
}
}
/*clock_t ini=clock();
t=((double)clock()-ini)/CLOCKS_PER_SEC;	
	printf("%f ms\n",t);
	*/
