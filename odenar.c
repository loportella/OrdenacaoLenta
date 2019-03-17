#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenar.h"
void Entrada(int n){
	srand(time(NULL));
	int i;
	unlink("Entrada.txt");
	FILE *f=fopen("Entrada.txt","w");
	for(int i=0;i<n;i++){
		fprintf(f,"%d ",1+rand()%50);
	}
	fclose(f);
}
void ReadEntrada(int n){
	FILE *f=fopen("Entrada.txt","r");
	int *v;v=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&v[i]);
		printf("%d ",v[i]);
	}printf("\n");free(v);fclose(f);
}
int *GetEntrada(int n){
	FILE *f=fopen("Entrada.txt","r");
	int *v,aux;
	v=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&aux);
		v[i]=aux;
	}fclose(f);return v;
}
void BubblesortMenu(int n){
	int op;float tb;
	tb=Bubblesort(n);
	do{
		printf("op ");scanf("%d",&op);
		switch(op){
			case 1: ReadEntrada(n);  break;
			case 2: ReadBubblesort(n); break;
			case 3: printf("%f segundos\n",tb);break;
		}
	}while(op!=0);printf("\n");
}
int Bubblesort(int n){
	int *v;v=GetEntrada(n);
	int i,j,aux;float t;
	clock_t inicio=clock();
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(v[i]>v[j]){
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;	}	}
	}t=((double)clock()-inicio)/CLOCKS_PER_SEC;
	WreadBubblesort(n,v);
	free(v);return t;
}
void WreadBubblesort(int n,int *v){
	unlink("Bubble sort.txt");
	FILE *f=fopen("Bubble sort.txt","w");
	for(int i=0;i<n;i++){
		fprintf(f,"%d ",v[i]);
	}fclose(f);
}
void ReadBubblesort(int n){
	FILE *f=fopen("Bubble sort.txt","r");
	int *v;v=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		fscanf(f,"%d ",&v[i]);
		printf("%d ",v[i]);
	}fclose(f);
}
