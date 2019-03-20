#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenar.h"
void menu(int i){
	if(i==0){
printf("1-Bubble sort\n2-Selection sort\n3-Insertion sort \t");
	}else{
printf("1-Mostrar arquivo Entrada.txt\n2-Mostrar arquivo ordenado\n3-Mostrar tempo de ordenacao\n0-SAIR \t");}
}
void criaarq(int n){
	srand(time(NULL));
	int i;
	FILE *f=fopen("Entrada.txt","w");
	for(int i=0;i<n;i++){
		fprintf(f,"%d ",0+rand()%(n*10));
	}	fclose(f);
}
void printEntrada(int n){
	FILE *f=fopen("Entrada.txt","r");
	int *v;v=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&v[i]);
		printf("%d ",v[i]);
	}printf("\n");free(v);fclose(f);
}
int *getEntrada(int n){
	FILE *f=fopen("Entrada.txt","r");
	int *v,a;
	v=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&a);
		v[i]=a;
	}fclose(f);return v;
}
void wreadSort(int n,int *v,int op){
	FILE *f;
	if(op==1){
	unlink("Bublesort.txt");
	f=fopen("Bublesort.txt","w");}
	else if(op==2){
	unlink("Selection.txt");
	f=fopen("Selection.txt","w");
	}else if(op==3){
		unlink("Insertion.txt");
		f=fopen("Insertion.txt","w");
	}
	for(int i=0;i<n;i++){
		fprintf(f,"%d ",v[i]);
	}fclose(f);
}
void readSort(int n,int op){
	FILE *f;
	if(op==1){
	f=fopen("Bublesort.txt","r");
}else if(op==2){
		f=fopen("Selection.txt","r");
}else if(op==3){
	f=fopen("Insertion.txt","r");
}
	int *v;v=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		fscanf(f,"%d ",&v[i]);
		printf("%d ",v[i]);
	}printf("\n");	fclose(f);
}
void menuBubble(int n){
	int op;
	float t=bubblesort(n);
	do{
		printf("MENU BUBBLE SORT:\n");menu(1);
		scanf("%d",&op);
		switch(op){
			case 1: printEntrada(n);  break;
			case 2: readSort(n,1); break;
			case 3:printf("%f segundos\n\n",t);break;
			default: printf("Opcao invalida\n");break;
		}
	}while(op!=0);
}
float bubblesort(int n){
	int *v;v=getEntrada(n);
	int i,j,aux;float t;
	printf("Bubble sort em andamento: ");
	clock_t inicio=clock();
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(v[i]>v[j]){
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;	}}
	}t=((double)clock()-inicio)/CLOCKS_PER_SEC;
	printf("\nBubble sort terminado\n");
	wreadSort(n,v,1);free(v);
	return t;
}
void menuSelection(int n){
	int op;
	float t=selectionsort(n);
	do{
		printf("MENU SELECTION SORT:");menu(1);
		scanf("%d",&op);
		switch(op){
		case 1: printEntrada(n);break;
		case 2:readSort(n,2); break;
		case 3:printf("%f segundos\n\n",t); break;
		default: printf("Opcao invalida\n");break;
       }
	}while(op!=0);
}
float selectionsort(int n){
	int i,j,a,b,t,*v;
	v=getEntrada(n);
	printf("Selection sort em andamento: ");
	clock_t inicio=clock();
	for(i=0;i<n;i++){
		a=v[i];
		for(j=i+1;j<n;j++){
			if(v[j]<a){
				b=a;
				a=v[j];
				v[j]=b;
			}v[i]=a;}
	}t=((double)clock()-inicio)/CLOCKS_PER_SEC;
	printf("\nSelection sort terminado\n");
	wreadSort(n,v,2);free(v);
	return t;
}
void menuInsertion(int n){
	int op;
	float t=insertionsort(n);
	do{
		printf("MENU INSERTION:\n ");menu(1);
		scanf("%d",&op);
		switch(op){
		case 1: printEntrada(n);break;
		case 2:readSort(n,3); break;
		case 3:printf("%f segundos\n\n",t); break;
		default: printf("Opcao invalida\n");break;
       }
	}while(op!=0);
}
float insertionsort(int n){
	int i,j,a,t,*v;
	v=getEntrada(n);
	printf("Insertion sort em andamento: ");
	clock_t inicio=clock();
	for(i=0;i<n;i++){
		j=i+1;while(j>0&&v[j]<v[j-1]){
			a=v[j];
			v[j]=v[j-1];
			v[j-1]=a; j--;
		}}t=((double)clock()-inicio)/CLOCKS_PER_SEC;
		printf("\nInsertion sort terminado\n");
		wreadSort(n,v,3);free(v);
		return t;
}	
